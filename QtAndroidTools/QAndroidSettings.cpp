/*
 *	MIT License
 *
 *	Copyright (c) 2018 Fabio Falsini <falsinsoft@gmail.com>
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */
#include <QCoreApplication>
#include "QAndroidSettings.h"

QAndroidSettings *QAndroidSettings::m_pInstance = nullptr;

QAndroidSettings::QAndroidSettings(QObject *parent) : QObject(parent),
    m_javaSettings("com/falsinsoft/qtandroidtools/AndroidSettings",
                                                                        "(Landroid/app/Activity;)V",
                                                                        QNativeInterface::QAndroidApplication::context())
{
    m_pInstance = this;
}

QAndroidSettings* QAndroidSettings::create(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    return new QAndroidSettings();
}

QAndroidSettings* QAndroidSettings::instance()
{
    return m_pInstance;
}

void QAndroidSettings::openTTSSettings()
{
    if(m_javaSettings.isValid())
    {
        m_javaSettings.callMethod<void>("openTTSSettings");
    }
}
