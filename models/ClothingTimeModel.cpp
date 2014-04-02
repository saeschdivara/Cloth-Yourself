/********************************************************************************
 ** The MIT License (MIT)
 **
 ** Copyright (c) 2013 Sascha Ludwig Häusler
 **
 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:
 **
 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *********************************************************************************/

#include "ClothingTimeModel.h"

#include <system/web/model/AbstractModel_p.h>

#include <system/web/form/CharField.h>
#include <system/web/form/DateField.h>
#include <system/web/form/ImageField.h>

#include <QtCore/QDebug>

int clothing_time_model_id = qRegisterMetaType<ClothingTimeModel *>("ClothingTimeModelPtr");

PU_DEFINE_MANAGER(ClothingTimeModel)

class ClothingTimeModelPrivate : public PublicServerSystem::Web::Model::AbstractModelPrivate
{
    public:
};

ClothingTimeModel::ClothingTimeModel(QObject *parent) :
    ClothingTimeModel(0, parent)
{
}

ClothingTimeModel::ClothingTimeModel(arangodb::Document *doc, QObject *parent) :
    PublicServerSystem::Web::Model::AbstractModel(doc, new ClothingTimeModelPrivate, parent)
{
}

QString ClothingTimeModel::title() const
{
    return get("title").toString();
}

void ClothingTimeModel::setTitle(const QString &title)
{
    set("title", title);
}

PublicServerSystem::Web::Form::AbstractFormField *ClothingTimeModel::titleField()
{
    return field<PublicServerSystem::Web::Form::CharField>("title", "The title");
}

QString ClothingTimeModel::image() const
{
    return get("image").toString();
}

QString ClothingTimeModel::imageUrl() const
{
    return get("image_url").toString();
}

void ClothingTimeModel::setImageUrl(const QString &url)
{
    set("image_url", url);
}

void ClothingTimeModel::setImage(const QString &image)
{
    set("image", image);
}

PublicServerSystem::Web::Form::AbstractFormField *ClothingTimeModel::imageField()
{
    return field<PublicServerSystem::Web::Form::ImageField>("image", "Image");
}

QDate ClothingTimeModel::startDate() const
{
    return get("start_date").toDate();
}

void ClothingTimeModel::setStartDate(const QDate &date)
{
    set("start_date", date);
}

PublicServerSystem::Web::Form::AbstractFormField *ClothingTimeModel::startDateField()
{
    return field<PublicServerSystem::Web::Form::DateField>("start_date", "Start date");
}

QDate ClothingTimeModel::endDate() const
{
    return get("end_date").toDate();
}

void ClothingTimeModel::setEndDate(const QDate &date)
{
    set("end_date", date);
}

PublicServerSystem::Web::Form::AbstractFormField *ClothingTimeModel::endDateField()
{
    return field<PublicServerSystem::Web::Form::DateField>("end_date", "End date");
}
