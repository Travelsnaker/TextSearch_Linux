/////////////////////////////////////////////////////////////
// FileMgr.h -  Implementation of IFileMgr interface       //
//              Define object factory.                     //
//              Build as DLL                               //
//                                                         //
// Platform:    MAC, Core i5, Ubuntu 15.10                 //
// Application: CSE775, Distributed Object, Project 1, 2016//
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi//
//              wsun13@syr.edu                             //
/////////////////////////////////////////////////////////////
/* 
 * Package Operations:
 * ====================
 * Implement IFileMgr interface. Provide functions to search 
 * files that residing in a given directory and match one or
 * more patterns. 
 * 
 * Public interface:
 * ====================
 * std::string get(); //Get the result from queue
 * size_t getNumFiles(); //Get the number of results
 * void SearchFile(const std::string&root,
 *                  std::vector<std::string>&patterns);
 * static IFileMgr*createFileMgr();
 * 
 * Required files:
 * ====================
 * FileMgr.h, FileMgr.cpp, Cpp11-BlockingQueue.h 
 * Cpp11-BlockingQueue.cpp,FileSystem.h, FileSystem.cpp
 * 
 * Maintain History
 * ====================
 * Ver 1.0 : 18 March
 * - first release
 */

#ifndef FILEMGR_H
#define FILEMGR_H
#include<string>
#include<vector>
#include "IFileMgr.h"
#include "../BlockingQueue/Cpp11-BlockingQueue.h"
#include "../FileSystem/FileSystem.h"
class FileMgr : public IFileMgr {
public:
    std::string get();
    size_t getNumFiles();
    void SearchFile(const std::string&root,
            std::vector<std::string>&patterns);
private:
    BlockingQueue<std::string>store;
    
};

#endif /* FILEMGR_H */

