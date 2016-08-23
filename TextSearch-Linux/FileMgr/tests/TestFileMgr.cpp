/////////////////////////////////////////////////////////////
// TestFileMgr.cpp- Uesd to test FileMgr component         //
//              
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



#include <stdlib.h>
#include <iostream>
#include "../IFileMgr.h"
#include <dlfcn.h>
#include <vector>

void test1(IFileMgr*pFileMgr) {
    std::cout << "root is .., patterns is \"*.cpp\" \"*.h\"" << std::endl;
    std::vector<std::string>patterns={"*.cpp","*.h"};
    pFileMgr->SearchFile("..",patterns);
    size_t num=pFileMgr->getNumFiles();
    std::cout<<"Qualified files are: "<<std::endl;
    while(num!=0)
    {
        std::cout<<"Qualified files: "<<pFileMgr->get()<<std::endl;
        --num;
    }
}


int main(int argc, char** argv) {
    std::cout<<"\n Demonstrate test FileMgr"<<std::endl;
    void*handle=dlopen("../FileMgr/dist/Debug/GNU-Linux/libFileMgr.so",RTLD_LAZY);
    if(!handle)
    {
        std::cout<<"\n Failed to load libFileMgr.so \n\n"<<std::endl;
        return 1;
    }
    typedef IFileMgr*(*GCreate)();
    GCreate gCreate=(GCreate)dlsym(handle,"globalCreateFileMgr");
    if(!gCreate)
    {
        std::cout<<"\n failed to acquire createFileMgr \n"<<std::endl;
        return 1;
    }
    IFileMgr*pFileMgr=gCreate();
    test1(pFileMgr);
    dlclose(handle);
    return (EXIT_SUCCESS);
}

