/////////////////////////////////////////////////////////////
// FileMgr.cpp -  Implementation of IFileMgr interface     //
//              Define object factory.                     //
//              Build as DLL                               //
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
#include "FileMgr.h"
#include <iostream>
#include "../BlockingQueue/Cpp11-BlockingQueue.h"
#include "../FileSystem/FileSystem.h"
using namespace FileSystem;
//----< search files residing in a directory given one or more patterns>----
void FileMgr::SearchFile(const std::string& root, std::vector<std::string>& patterns)
{
    FileInfo fn(root);
    if(fn.isDirectory())
    {
        std::vector<std::string>currFiles;
        for(size_t i=0;i<patterns.size();++i)
        {
            std::vector<std::string>currFilesTemp=Directory::getFiles(root,patterns[i]);
            currFiles.insert(currFiles.end(),currFilesTemp.begin(),currFilesTemp.end());            
        }
        for(size_t i=0;i<currFiles.size();++i)
        {
            store.enQ(root+"/"+currFiles[i]);
        }
        std::vector<std::string>currDirs=Directory::getDirectories(root);
        for(size_t i=0;i<currDirs.size();++i)
            if(currDirs[i]!="."&&currDirs[i]!="..")
                SearchFile(root+"/"+currDirs[i],patterns);
    }
}
//----< Get the result >-----
std::string FileMgr::get()
{
    return store.deQ();
}
//----< Get number of results>----
size_t FileMgr::getNumFiles()
{
    return store.size();
}
//----<object factory>-----
IFileMgr*IFileMgr::createFileMgr()
{
    return new FileMgr;
}
//-----<global object factory>-----
IFileMgr*globalCreateFileMgr()
{
    return new FileMgr;
}




