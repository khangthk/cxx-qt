// clang-format off
// SPDX-FileCopyrightText: 2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// clang-format on
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0
#include <QtCore/QScopedPointer>
#include <QtTest/QTest>

#include "cxxqtconvert.h"
#include "qbytearray.h"
#include "qcolor.h"
#include "qcoreapplication.h"
#include "qdate.h"
#include "qdatetime.h"
#include "qguiapplication.h"
#include "qhash.h"
#include "qlist.h"
#include "qmap.h"
#include "qmodelindex.h"
#include "qpersistentmodelindex.h"
#include "qpoint.h"
#include "qpointf.h"
#include "qrect.h"
#include "qrectf.h"
#include "qset.h"
#include "qsize.h"
#include "qsizef.h"
#include "qstring.h"
#include "qstringlist.h"
#include "qtime.h"
#include "qurl.h"
#include "qvariant.h"
#include "qvector.h"
#include "qvector2d.h"
#include "qvector3d.h"
#include "qvector4d.h"

int
main(int argc, char* argv[])
{
  int status = 0;
  auto runTest = [&status, argc, argv](QScopedPointer<QObject> obj) {
    if (status == 0) {
      status |= QTest::qExec(obj.data(), argc, argv);
    } else {
      qWarning() << "Previous test failed, so skipping:" << obj.data();
    }
  };

  runTest(QScopedPointer<QObject>(new CxxQtConvertTest));
  runTest(QScopedPointer<QObject>(new QByteArrayTest));
  runTest(QScopedPointer<QObject>(new QColorTest));
  runTest(QScopedPointer<QObject>(new QCoreApplicationTest));
  runTest(QScopedPointer<QObject>(new QDateTest));
  runTest(QScopedPointer<QObject>(new QDateTimeTest));
  runTest(QScopedPointer<QObject>(new QGuiApplicationTest));
  runTest(QScopedPointer<QObject>(new QHashTest));
  runTest(QScopedPointer<QObject>(new QListTest));
  runTest(QScopedPointer<QObject>(new QMapTest));
  runTest(QScopedPointer<QObject>(new QModelIndexTest));
  runTest(QScopedPointer<QObject>(new QPersistentModelIndexTest));
  runTest(QScopedPointer<QObject>(new QPointTest));
  runTest(QScopedPointer<QObject>(new QPointFTest));
  runTest(QScopedPointer<QObject>(new QRectTest));
  runTest(QScopedPointer<QObject>(new QRectFTest));
  runTest(QScopedPointer<QObject>(new QSetTest));
  runTest(QScopedPointer<QObject>(new QSizeTest));
  runTest(QScopedPointer<QObject>(new QSizeFTest));
  runTest(QScopedPointer<QObject>(new QStringTest));
  runTest(QScopedPointer<QObject>(new QStringListTest));
  runTest(QScopedPointer<QObject>(new QTimeTest));
  runTest(QScopedPointer<QObject>(new QUrlTest));
  runTest(QScopedPointer<QObject>(new QVariantTest));
  runTest(QScopedPointer<QObject>(new QVectorTest));
  runTest(QScopedPointer<QObject>(new QVector2DTest));
  runTest(QScopedPointer<QObject>(new QVector3DTest));
  runTest(QScopedPointer<QObject>(new QVector4DTest));

  return status;
}
