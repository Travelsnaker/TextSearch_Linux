/////////////////////////////////////////////////////////////
// IFileMgr.h - Define the interface of FileMgr component  //
//                                                         //
// Platform:    MAC, Core i5, Ubuntu 15.10                 //
// Application: CSE775, Distributed Object, Project 1, 2016//
// Author:      Wei Sun, Computer Engineering, Syracuse Unvi//
//              wsun13@syr.edu                             //
/////////////////////////////////////////////////////////////
/* 
 * Package Operations:
 * ====================
 * This file defines the interface of FileMgr component.
 * 
 * Public Interface:
 * ====================
 * std::string get(); //Get the result from queue
 * size_t getNumFiles(); //Get the number of results
 * void SearchFile(const std::string&root,
 *                  std::vector<std::string>&patterns);
 * static IFileMgr*createFileMgr();
 * extern "C"{
 *  IFileMgr*globalCreateFileMgr();
 * }
 * 
 * Required files:
 * ====================
 * IFileMgr.h
 * 
 * Maintenance History:
 * ====================
 * Ver 1.0 : 18 March
 * - first release
 */

#ifndef IFILEMGR_H
#define IFILEMGR_H
#include<string>
#include<vector>

class IFileMgr {
public:
    virtual std::string get() = 0;
    virtual size_t getNumFiles() = 0;
    virtual void SearchFile(const std::string&root,
            std::vector<std::string>&patterns) = 0;
    static IFileMgr*createFileMgr();
};

extern "C"{
    IFileMgr*globalCreateFileMgr();
}


#endif /* IFILEMGR_H */

