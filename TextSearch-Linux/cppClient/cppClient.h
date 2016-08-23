/////////////////////////////////////////////////////////////
// cppClient.h- Provide functions to build a text search    //
//              console application.                       //
//                                                         //
//                                                         //
// Platform:    MAC, Core i5, Ubuntu 15.10                 //
// Application: CSE775, Distributed Object, Project 1, 2016//
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi//
//              wsun13@syr.edu                             //
/////////////////////////////////////////////////////////////
/*
 * Package operations:
 * ===================
 * Provides functions to build a text search console application.
 * 
 * Public Interface:
 * ===================
 * cppClient();
 * ~cppClient();
 * void setupSearch(const std::string&root,
 *                  const std::string&text,
 *                  int numOfThreads,
 *                  std::vector<std::string>&patterns,
 *                  long long time=3);
 * void startSearch();
 * void stopSearch();
 * 
 * Required files:
 * ===================
 * cppClient.h,cppClient.cpp, IFileMgr.h, ITextSearch.h
 * 
 * Maintain History
 * ====================
 * Ver 1.0 : 18 March
 * - first release
 */

/* 
 * File:   cppClient.h
 * Author: weisun
 *
 * Created on March 20, 2016, 6:22 PM
 */

#ifndef CPPCLIENT_H
#define CPPCLIENT_H
#include "../FileMgr/IFileMgr.h"
#include "../TextSearch/ITextSearch.h"
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<dlfcn.h>

class cppClient {
public:
    cppClient();
    ~cppClient();
    void setupSearch(const std::string&root,
                     const std::string&text,
                     int numOfThreads,
                     std::vector<std::string>&patterns,
                     long long time=1);
    void startSearch();
    void stopSearch();
private:
    IFileMgr*pFileMgr;
    ITextSearch*pText;
    void*tHandle;
    void*fHandle;
    std::string root;
    std::string text;
    int numOfThreads;
    std::vector<std::string>patterns;
    bool stop;
    long long timeLimit;
};

#endif /* CPPCLIENT_H */

