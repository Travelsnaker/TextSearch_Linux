/////////////////////////////////////////////////////////////////
// TextSearch.cpp-Provides functions to search a specific string//
//              in a file. Define object factory. Build as DLL //
//                                                           //
// Platform:    MAC, Core i5, Ubuntu 15.10                   //
// Application: CSE775, Distributed Object, Project 1, 2016  //
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi //
//              wsun13@syr.edu                               //
///////////////////////////////////////////////////////////////
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TextSearch.h"

//-----< Enqueue filename into TextSearch component >----
void TextSearch::enqueue(const std::string&filename)
{
    input.enQ(filename);
}
//-----< Get the text search result >----
std::string TextSearch::get()
{
    return output.deQ();
}
//-----<Get the number of results>----
size_t TextSearch::getNumRes()
{
    return output.size();
}
//-----< set all the text search parameters >-----
void TextSearch::setupSearch(int NumOfThreads, const std::string& text)
{
    _stop=false;
    std::string txt=text;
    for(int i=0;i<NumOfThreads;++i)
    {
        threads.push_back(std::thread(&TextSearch::textSearch,this,txt));
    }
}
//----<start asychronous text search >-----
void TextSearch::startSearch()
{
    for(auto&t:threads)
        t.detach();
}
//-----< Search a string in a single file >----
bool TextSearch::TxtSearch(const std::string& filename, const std::string& text)
{
    std::ostringstream temp;
    std::ifstream in(filename);
    if(in.good())
    {
        temp<<in.rdbuf();
        const std::string&contents=temp.str();
        size_t pos=contents.find(text);
        if(pos!=std::string::npos)
        {
            return true;
        }
    }
    return false;
}
//----< Search text accroding to the filename>----
void TextSearch::textSearch(std::string text)
{
    while(true)
    {
        if(_stop)
            break;
        std::string filename=input.deQ();
        if(TxtSearch(filename,text))
        {
            output.enQ(filename);
        }
    }
}
//----< stop text search >-----
void TextSearch::stopSearch()
{
    _stop=true;
}
//----< object factory >----
ITextSearch* ITextSearch::createTextSearch()
{
    return new TextSearch;
}
//----< global object factory>-----
ITextSearch*globalCreateTextSearch()
{
    return new TextSearch;
}