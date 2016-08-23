/////////////////////////////////////////////////////////////////
// TextSearch.h-Provides functions to search a specific string //
//              in a file. Define object factory. Build as DLL //
//                                                           //
// Platform:    MAC, Core i5, Ubuntu 15.10                   //
// Application: CSE775, Distributed Object, Project 1, 2016  //
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi //
//              wsun13@syr.edu                               //
///////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * ====================
 * Provides functions to search a specific string in a file. Define
 * a object factory.
 * 
 * Public Interface:
 * =====================
 * void enqueue(const std::string&filename);
 * std::string get();
 * size_t getNumRes();
 * void setupSearch(int NumOfThreads,const std::string&text);
 * void startSearch();
 * void stopSearch();
 * static ITextSearch*createTextSearch();
 * ITextSearch*globalCreateTextSearch();
 * 
 * Required files
 * ====================
 * ITextSearch.h, TextSearch.h, TextSearch.cpp,
 * Cpp11-BlockingQueue.h, Cpp11-BlockingQueue.cpp,
 * FileSystem.h, FileSystem.cpp
 * 
 * Maintenance History:
 * ====================
 * Ver 1.0 : 18 March
 * - first release
 * 
 */


#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H
#include "ITextSearch.h"
#include<string>
#include<thread>
#include<vector>
#include "../BlockingQueue/Cpp11-BlockingQueue.h"
#include "../FileSystem/FileSystem.h"

class TextSearch : public ITextSearch 
{
public:
    void enqueue(const std::string&filename);
    std::string get();
    size_t getNumRes();
    void setupSearch(int NumOfThreads,const std::string&text);
    void startSearch();
    void stopSearch();
private:
    BlockingQueue<std::string>input;
    BlockingQueue<std::string>output;
    std::vector<std::thread>threads;
    bool _stop=false;
    void textSearch(std::string text);
    bool TxtSearch(const std::string&filename,const std::string&text);
};


#endif /* TEXTSEARCH_H */

