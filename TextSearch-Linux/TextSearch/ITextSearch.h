///////////////////////////////////////////////////////////////
// ITextSearch.h-Define the interface of TextSearch component//
//                                                           //
// Platform:    MAC, Core i5, Ubuntu 15.10                   //
// Application: CSE775, Distributed Object, Project 1, 2016  //
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi //
//              wsun13@syr.edu                               //
///////////////////////////////////////////////////////////////
/*
 * Operation:
 * =============
 * Define interface of TextSearch component.
 * 
 * Public Interface:
 * ===============
 * virtual void enqueue(const std::string&filename)=0;
 * virtual std::string get()=0;
 * virtual void setupSearch(int NumOfThreads,const std::string&text)=0;
 * virtual void startSearch()=0;
 * virtual void stopSearch()=0;
 * static ITextSearch*createTextSearch();
 * extern "C"{
 *  ITextSearch*globalCreateTextSearch();
 * }
 * 
 * Required files:
 * ================
 * ITextSearch.h
 * 
 * Maintenance History:
 * ====================
 * Ver 1.0 : 18 March
 * - first release
 * 
 * /

/* 
 * File:   ITextSearch.h
 * Author: weisun
 *
 * Created on March 18, 2016, 7:21 PM
 */

#ifndef ITEXTSEARCH_H
#define ITEXTSEARCH_H
#include <string>

class ITextSearch
{
public:
    virtual void enqueue(const std::string&filename)=0;
    virtual std::string get()=0;
    virtual size_t getNumRes()=0;
    virtual void setupSearch(int NumOfThreads,const std::string&text)=0;
    virtual void startSearch()=0;
    virtual void stopSearch()=0;
    static ITextSearch*createTextSearch();
};

extern "C"{
    ITextSearch*globalCreateTextSearch();
}

#endif /* ITEXTSEARCH_H */

