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

#include "ClothingWebsite.h"

#include "models/ClothingTimeModel.h"
#include "models/ClothModel.h"

#include "views/IndexView.h"
#include "views/ClothingTimeView.h"

#include <system/web/AbstractSite_p.h>

#include <lib/cachingloaderdecorator.h>
#include <lib/engine.h>
#include <lib/template.h>

#include <QtCore/QDebug>

class ClothingWebsitePrivate : public PublicServerSystem::Web::AbstractSitePrivate
{
    public:
};

ClothingWebsite::ClothingWebsite(QObject *parent) :
    PublicServerSystem::Web::AbstractSite(new ClothingWebsitePrivate, parent)
{
    Q_D(ClothingWebsite);

    Grantlee::FileSystemTemplateLoader::Ptr loader( new Grantlee::FileSystemTemplateLoader() );
    // This path should point to the source of this code
    loader->setTemplateDirs( QStringList() << "./templates" );

#ifdef Q_NO_DEBUG
    Grantlee::CachingLoaderDecorator::Ptr cache( new Grantlee::CachingLoaderDecorator( loader ) );
    d->engine->addTemplateLoader(cache);
#else
    d->engine->addTemplateLoader(loader);
#endif

    d->engine->addPluginPath("./plugins");

    addView(QLatin1String("^/clothing-time/"), new ClothingTimeView);
    addView(QLatin1String("^/"), new IndexView);

    ClothingTimeModel::objects->registerDatabaseModel();
    ClothModel::objects->registerDatabaseModel();
}
