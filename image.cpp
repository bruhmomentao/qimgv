#include "image.h"
#include <QMovie>

Image::Image() : QObject(), mPath()
{
}

Image::Image(QString path) : QObject(), mPath(path)
{
    loadImage(path);
}

Image::Image(FileInfo *_info) : QObject()
{
    info=_info;
    loadImage(info->getPath());
}

Image::~Image()
{
    free(data);
}

void Image::loadImage(QString path)
{
    if(getType() == GIF) {
        data = new QMovie(path);
    }
    else if(getType() == STATIC) {
        data = new QPixmap(path);
    }
}

QMovie* Image::getMovie() const
{
    return movie;
}

QPixmap* Image::getPixmap() const
{
    return pixmap;
}

int Image::getType() const
{
    return info->getType();
}

QString Image::getPath() const
{
    return info->getPath();
}