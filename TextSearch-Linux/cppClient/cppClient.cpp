/////////////////////////////////////////////////////////////
// cppClient.cpp-Provide functions to build a text search  //
//              console application.                       //
//                                                         //
//                                                         //
// Platform:    MAC, Core i5, Ubuntu 15.10                 //
// Application: CSE775, Distributed Object, Project 1, 2016//
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi//
//              wsun13@syr.edu                             //
/////////////////////////////////////////////////////////////
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cppClient.h"
using namespace std;

//----< default constructor of cppClient >----
cppClient::cppClient()
{
    //tHandle=dlopen("../TextSearch/dist/Debug/GNU-Linux/libTextSearch.so",RTLD_LAZY);
    tHandle=dlopen("../TextSearch/dist/Debug/GNU-Linux/libTextSearch.so",RTLD_LAZY);
    if(!tHandle)
    {
        std::cout<<"\n Failed to load libTextSearch.so"<<std::endl;
        return;
    }
    fHandle=dlopen("../FileMgr/dist/Debug/GNU-Linux/libFileMgr.so",RTLD_LAZY);
    if(!fHandle)
    {
        std::cout<<"\n Failed to load libFileMgr.so \n\n"<<std::endl;
        return;
    }
    typedef IFileMgr*(*GCreate)();
    typedef ITextSearch*(*TCreate)();
    TCreate tCreate=(TCreate)dlsym(tHandle,"globalCreateTextSearch");
    GCreate gCreate=(GCreate)dlsym(fHandle,"globalCreateFileMgr");
    if(!gCreate)
    {
        std::cout<<"\n failed to acquire createFileMgr \n"<<std::endl;
        return;
    }
    if(!tCreate)
    {
        std::cout<<"\n failed to acquire createTextSearch \n"<<std::endl;
        return;
    }
    pFileMgr=gCreate();
    pText=tCreate();
}
//----< default constructor of cppClient>----
cppClient::~cppClient()
{
    dlclose(tHandle);
    dlclose(fHandle);
}
//----< set all the parameters for a text search>----
void cppClient::setupSearch(const std::string&_root, 
                            const std::string&_text, 
                            int _numOfThreads, 
                            std::vector<std::string>&_patterns, 
                            long long time)
{
    if(pFileMgr!=0&&pText!=0)
    {
        timeLimit=time;
        stop=false;
        root=_root;
        text=_text;
        patterns=_patterns;
        numOfThreads=_numOfThreads;
    }
}
//-----< start asychronous search >-----
void cppClient::startSearch()
{
    if(pFileMgr!=0&&pText!=0)
    {
        std::thread t([&](){
            pFileMgr->SearchFile(root,patterns);
            pText->setupSearch(numOfThreads,text);
            size_t num=pFileMgr->getNumFiles();
            while(num!=0)
            {
                std::string file=pFileMgr->get();
                //cout<<"Search result: "<<file<<endl;
                pText->enqueue(file);
                --num;
            }
            while(true)
            {
                if(stop)
                {
                    pText->stopSearch();
                    break;
                }
                std::string res=pText->get();
                std::cout<<"Text search result: "<<res<<std::endl;
            }            
        });
        t.detach();
        std::this_thread::sleep_for(std::chrono::seconds(timeLimit));
    }
}
//-----< stop text search >-----
void cppClient::stopSearch()
{
    stop=true;
}
//-----< test stub>----
//-----<convert an array of char to int>-----
int toInt(char*ch)
{
    int res=0;
    while(*ch!='\0')
    {
        res=10*res+(*ch-'0');
        ++ch;
    }
    return res;
}

int main(int argc, char** argv) {
    if(argc<5)
    {
        std::cout<<"\n lack of commandline arguments \n\n";
        return 1;
    }
    std::vector<std::string>patterns;
    for(int i=4;i<argc;++i)
    {
        patterns.push_back(argv[i]);
    }
    cppClient app;
    app.setupSearch(argv[1],argv[2],toInt(argv[3]),patterns);
    app.startSearch();
    app.stopSearch();
    return 0;
}