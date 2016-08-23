/////////////////////////////////////////////////////////////////
// TestTextSearch.cpp - test TextSearch component              //
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

/* 
 * File:   TestTextSearch.cpp
 * Author: weisun
 *
 * Created on March 22, 2016, 11:16 AM
 */

#include <stdlib.h>
#include <iostream>
#include "../ITextSearch.h"
#include <dlfcn.h>
/*
 * Simple C++ Test Suite
 */
//-----< test stub >----
#ifdef TEST_TEXTSEARCH
void test1(ITextSearch*pText) {
    std::cout<<"\n Test asychronous text search"<<std::endl;
    std::cout << "\n Number of threads is set to 4, search string is \"main\"" << std::endl;
    pText->setupSearch(4,"#include");
    pText->startSearch();
    pText->enqueue("../TextSearch/ITextSearch.h");
    pText->enqueue("../TextSearch/Makefile");
    pText->enqueue("../TextSearch/TextSearch.cpp");
    pText->enqueue("../TextSearch/TextSearch.h");
    pText->enqueue("../TextSearch/tests/TestTextSearch.cpp");
    size_t num=pText->getNumRes();
    std::cout<<"Text search results are: "<<std::endl;
    while(num!=0)
    {
        std::cout<<"Text Search Result: "<<pText->get()<<std::endl;
        num=pText->getNumRes();
    }
}


int main(int argc, char** argv) {
    std::cout<<"\n Demonstrate TextSearch component"<<std::endl;
    void*handle=dlopen("../TextSearch/dist/Debug/GNU-Linux/libTextSearch.so",RTLD_LAZY);
    if(!handle)
    {
        std::cout<<"\n Failed to load libFileMgr.so \n\n"<<std::endl;
        return 1;
    }
    typedef ITextSearch*(*TCreate)();
    TCreate tCreate=(TCreate)dlsym(handle,"globalCreateTextSearch");
    if(!tCreate)
    {
        std::cout<<"\n failed to acquire createTextSearch \n"<<std::endl;
        return 1;
    }
    ITextSearch*pText=tCreate();
    test1(pText);
    dlclose(handle);
    return (EXIT_SUCCESS);
}
#endif

