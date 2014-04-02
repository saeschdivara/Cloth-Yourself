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

#ifndef CLOTHINGTIMEMODEL_H
#define CLOTHINGTIMEMODEL_H

#include <system/web/form/AbstractFormField.h>

#include <system/web/model/AbstractModel.h>
#include <system/web/model/ModelManager.h>

#include <QtCore/QDate>

class ClothingTimeModelPrivate;

class ClothingTimeModel : public PublicServerSystem::Web::Model::AbstractModel
{
        Q_OBJECT
        Q_PROPERTY(QString title READ title WRITE setTitle)
        Q_PROPERTY(PublicServerSystem::Web::Form::AbstractFormField* title_field READ titleField)

        Q_PROPERTY(QString image READ image WRITE setImage)
        Q_PROPERTY(PublicServerSystem::Web::Form::AbstractFormField* image_field READ imageField)
        Q_PROPERTY(QString image_url READ imageUrl WRITE setImageUrl)

        Q_PROPERTY(QDate start_date READ startDate WRITE setStartDate)
        Q_PROPERTY(PublicServerSystem::Web::Form::AbstractFormField* start_date_field READ startDateField)

        Q_PROPERTY(QDate end_date READ endDate WRITE setEndDate)
        Q_PROPERTY(PublicServerSystem::Web::Form::AbstractFormField* end_date_field READ endDateField)
    public:
        explicit ClothingTimeModel(QObject *parent = 0);
        ClothingTimeModel(arangodb::Document * doc, QObject *parent = 0);

        // Title
        QString title() const;
        void setTitle(const QString & title);

        PublicServerSystem::Web::Form::AbstractFormField * titleField();

        // Image
        QString image() const;
        void setImage(const QString & image);

        QString imageUrl() const;
        void setImageUrl(const QString & url);

        PublicServerSystem::Web::Form::AbstractFormField * imageField();

        // Start date
        QDate startDate() const;
        void setStartDate(const QDate & date);

        PublicServerSystem::Web::Form::AbstractFormField * startDateField();

        // End date
        QDate endDate() const;
        void setEndDate(const QDate & date);

        PublicServerSystem::Web::Form::AbstractFormField * endDateField();

        PU_DECLARE_MANAGER(ClothingTimeModel);

    private:
        Q_DECLARE_PRIVATE(ClothingTimeModel)
};

typedef QList<ClothingTimeModel *> ClothingTimeModelList;

Q_DECLARE_METATYPE(ClothingTimeModel)
Q_DECLARE_METATYPE(ClothingTimeModelList)

#endif // CLOTHINGTIMEMODEL_H
