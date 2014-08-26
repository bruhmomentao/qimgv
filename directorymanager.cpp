#include "directorymanager.h"

DirectoryManager::DirectoryManager() :
    currentPosition(-1)
{
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.gif" << "*.bmp";
    fileInfo = new FileInfo();
    currentDir.setNameFilters(filters);
    clearFileInfo();
}

void DirectoryManager::setCurrentDir(QString path) {
    if(currentDir.currentPath() != path) {
        currentDir.setCurrent(path);
        currentDir.setNameFilters(filters);
        fileList = currentDir.entryList();
        currentPosition = -1;
        emit directoryChanged(path);
    }
}

void DirectoryManager::next() {
    if(currentDir.exists() && fileList.length()) {
        if(++currentPosition>=fileList.length()) {
            currentPosition=0;
        }
        QString fileName = currentDir.currentPath()
                        +"/"
                        +fileList.at(currentPosition);
        fileInfo->setFile(fileName);
    }
}

void DirectoryManager::prev() {
    if(currentDir.exists() && fileList.length()) {
        if(--currentPosition<0) {
            currentPosition=fileList.length()-1;
        }
        QString fileName = currentDir.currentPath()
                        +"/"
                        +fileList.at(currentPosition);
        fileInfo->setFile(fileName);
    }
}

fileType DirectoryManager::setFile(QString _path) {
    return fileInfo->setFile(_path);
}

FileInfo* DirectoryManager::getFile() {
    return fileInfo;
}

void DirectoryManager::clearFileInfo() {
    fileInfo = new FileInfo();
}