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

#include "ClothingTimeView.h"

#include "models/ClothingTimeModel.h"

#include <system/web/form/ModelForm.h>

#include <lib/template.h>

void ClothingTimeView::render(QTextStream &stream,
                              Grantlee::Engine *templateEngine,
                              Grantlee::Context *requestContext,
                              PublicServerSystem::Web::UserSession *session)
{
    QHash<QString, QString> postData = session->post();
    QString id = postData.value("id");
    ClothingTimeModel * model = Q_NULLPTR;

    if ( !id.isEmpty() ) {
        model = ClothingTimeModel::objects->get(id);
    }

    if ( model == Q_NULLPTR ) {
        model = ClothingTimeModel::objects->create();
        model->save();
    }

    PublicServerSystem::Web::Form::ModelForm form(model, &postData);

    if ( form.isValid() ) form.save();

    QString formOutput = form.toString();

    requestContext->insert(QLatin1String("editing_form"), formOutput);

    PublicServerSystem::Web::View::render("ClothingTimeView.html", stream, templateEngine, requestContext);

    model->deleteLater();
}
