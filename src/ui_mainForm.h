/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMainForm
{
public:
    QFrame *frameOrig;
    QFrame *frameDest;
    QPushButton *pushButtonCargar;
    QLabel *labelOrig;
    QLabel *labelDest;
    QPushButton *pushButtonCopiarO;
    QPushButton *pushButtonCopiarD;
    QPushButton *pushButtonBorrar;
    QFrame *options;
    QPushButton *pushButtonNegar;
    QPushButton *pushButtonUmbralizar;
    QLabel *labelMat;
    QPushButton *pushButtonSalir;
    QFrame *options_2;
    QSpinBox *spinUdetv;
    QPushButton *pushButtonDetectarH;
    QPushButton *pushButtonDetectarV;
    QLabel *labelDest_2;
    QLabel *labelDest_5;
    QSpinBox *spinUdeth;
    QFrame *options_3;
    QSpinBox *spinAncho;
    QLabel *labelDest_3;
    QLabel *labelDest_4;
    QSpinBox *spinAlto;
    QPushButton *pushButtonRecortar;
    QPushButton *pushButtonMatching;
    QFrame *frameD0;
    QFrame *frameD1;
    QFrame *frameD2;
    QFrame *frameD3;
    QFrame *frameD4;
    QFrame *frameD5;
    QFrame *frameD6;
    QPushButton *pushButtonTodo;

    void setupUi(QWidget *QMainForm)
    {
        if (QMainForm->objectName().isEmpty())
            QMainForm->setObjectName(QString::fromUtf8("QMainForm"));
        QMainForm->resize(732, 351);
        frameOrig = new QFrame(QMainForm);
        frameOrig->setObjectName(QString::fromUtf8("frameOrig"));
        frameOrig->setGeometry(QRect(10, 40, 320, 100));
        frameOrig->setFrameShape(QFrame::StyledPanel);
        frameOrig->setFrameShadow(QFrame::Raised);
        frameDest = new QFrame(QMainForm);
        frameDest->setObjectName(QString::fromUtf8("frameDest"));
        frameDest->setGeometry(QRect(400, 40, 320, 100));
        frameDest->setFrameShape(QFrame::StyledPanel);
        frameDest->setFrameShadow(QFrame::Raised);
        pushButtonCargar = new QPushButton(QMainForm);
        pushButtonCargar->setObjectName(QString::fromUtf8("pushButtonCargar"));
        pushButtonCargar->setGeometry(QRect(330, 0, 71, 30));
        labelOrig = new QLabel(QMainForm);
        labelOrig->setObjectName(QString::fromUtf8("labelOrig"));
        labelOrig->setGeometry(QRect(100, 10, 131, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setBold(true);
        font.setWeight(75);
        labelOrig->setFont(font);
        labelOrig->setAlignment(Qt::AlignCenter);
        labelDest = new QLabel(QMainForm);
        labelDest->setObjectName(QString::fromUtf8("labelDest"));
        labelDest->setGeometry(QRect(490, 10, 141, 20));
        labelDest->setFont(font);
        labelDest->setAlignment(Qt::AlignCenter);
        pushButtonCopiarO = new QPushButton(QMainForm);
        pushButtonCopiarO->setObjectName(QString::fromUtf8("pushButtonCopiarO"));
        pushButtonCopiarO->setGeometry(QRect(340, 100, 51, 27));
        pushButtonCopiarD = new QPushButton(QMainForm);
        pushButtonCopiarD->setObjectName(QString::fromUtf8("pushButtonCopiarD"));
        pushButtonCopiarD->setGeometry(QRect(340, 50, 51, 27));
        pushButtonBorrar = new QPushButton(QMainForm);
        pushButtonBorrar->setObjectName(QString::fromUtf8("pushButtonBorrar"));
        pushButtonBorrar->setGeometry(QRect(330, 150, 71, 27));
        options = new QFrame(QMainForm);
        options->setObjectName(QString::fromUtf8("options"));
        options->setGeometry(QRect(20, 160, 281, 51));
        options->setFrameShape(QFrame::Box);
        options->setFrameShadow(QFrame::Raised);
        pushButtonNegar = new QPushButton(options);
        pushButtonNegar->setObjectName(QString::fromUtf8("pushButtonNegar"));
        pushButtonNegar->setGeometry(QRect(10, 10, 111, 27));
        pushButtonUmbralizar = new QPushButton(options);
        pushButtonUmbralizar->setObjectName(QString::fromUtf8("pushButtonUmbralizar"));
        pushButtonUmbralizar->setGeometry(QRect(130, 10, 131, 27));
        labelMat = new QLabel(QMainForm);
        labelMat->setObjectName(QString::fromUtf8("labelMat"));
        labelMat->setGeometry(QRect(460, 230, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelMat->setFont(font1);
        labelMat->setAlignment(Qt::AlignCenter);
        pushButtonSalir = new QPushButton(QMainForm);
        pushButtonSalir->setObjectName(QString::fromUtf8("pushButtonSalir"));
        pushButtonSalir->setGeometry(QRect(330, 310, 71, 27));
        options_2 = new QFrame(QMainForm);
        options_2->setObjectName(QString::fromUtf8("options_2"));
        options_2->setGeometry(QRect(20, 220, 281, 121));
        options_2->setFrameShape(QFrame::Box);
        options_2->setFrameShadow(QFrame::Raised);
        spinUdetv = new QSpinBox(options_2);
        spinUdetv->setObjectName(QString::fromUtf8("spinUdetv"));
        spinUdetv->setGeometry(QRect(70, 30, 51, 20));
        spinUdetv->setMinimum(1);
        spinUdetv->setMaximum(20);
        spinUdetv->setValue(13);
        pushButtonDetectarH = new QPushButton(options_2);
        pushButtonDetectarH->setObjectName(QString::fromUtf8("pushButtonDetectarH"));
        pushButtonDetectarH->setGeometry(QRect(130, 60, 141, 27));
        pushButtonDetectarV = new QPushButton(options_2);
        pushButtonDetectarV->setObjectName(QString::fromUtf8("pushButtonDetectarV"));
        pushButtonDetectarV->setGeometry(QRect(130, 30, 141, 27));
        labelDest_2 = new QLabel(options_2);
        labelDest_2->setObjectName(QString::fromUtf8("labelDest_2"));
        labelDest_2->setGeometry(QRect(10, 31, 61, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        labelDest_2->setFont(font2);
        labelDest_2->setAlignment(Qt::AlignCenter);
        labelDest_5 = new QLabel(options_2);
        labelDest_5->setObjectName(QString::fromUtf8("labelDest_5"));
        labelDest_5->setGeometry(QRect(10, 62, 61, 20));
        labelDest_5->setFont(font2);
        labelDest_5->setAlignment(Qt::AlignCenter);
        spinUdeth = new QSpinBox(options_2);
        spinUdeth->setObjectName(QString::fromUtf8("spinUdeth"));
        spinUdeth->setGeometry(QRect(70, 61, 51, 20));
        spinUdeth->setMinimum(1);
        spinUdeth->setMaximum(20);
        spinUdeth->setValue(3);
        options_3 = new QFrame(QMainForm);
        options_3->setObjectName(QString::fromUtf8("options_3"));
        options_3->setGeometry(QRect(430, 260, 271, 81));
        options_3->setFrameShape(QFrame::Box);
        options_3->setFrameShadow(QFrame::Raised);
        spinAncho = new QSpinBox(options_3);
        spinAncho->setObjectName(QString::fromUtf8("spinAncho"));
        spinAncho->setEnabled(false);
        spinAncho->setGeometry(QRect(70, 10, 60, 20));
        spinAncho->setMinimum(20);
        spinAncho->setMaximum(50);
        spinAncho->setValue(32);
        labelDest_3 = new QLabel(options_3);
        labelDest_3->setObjectName(QString::fromUtf8("labelDest_3"));
        labelDest_3->setGeometry(QRect(10, 10, 51, 21));
        labelDest_3->setFont(font2);
        labelDest_3->setAlignment(Qt::AlignCenter);
        labelDest_4 = new QLabel(options_3);
        labelDest_4->setObjectName(QString::fromUtf8("labelDest_4"));
        labelDest_4->setGeometry(QRect(10, 50, 51, 21));
        labelDest_4->setFont(font2);
        labelDest_4->setAlignment(Qt::AlignCenter);
        spinAlto = new QSpinBox(options_3);
        spinAlto->setObjectName(QString::fromUtf8("spinAlto"));
        spinAlto->setEnabled(false);
        spinAlto->setGeometry(QRect(70, 50, 60, 20));
        spinAlto->setMinimum(1);
        spinAlto->setMaximum(100);
        spinAlto->setValue(55);
        pushButtonRecortar = new QPushButton(options_3);
        pushButtonRecortar->setObjectName(QString::fromUtf8("pushButtonRecortar"));
        pushButtonRecortar->setGeometry(QRect(180, 10, 81, 27));
        pushButtonMatching = new QPushButton(options_3);
        pushButtonMatching->setObjectName(QString::fromUtf8("pushButtonMatching"));
        pushButtonMatching->setGeometry(QRect(180, 40, 81, 27));
        frameD0 = new QFrame(QMainForm);
        frameD0->setObjectName(QString::fromUtf8("frameD0"));
        frameD0->setGeometry(QRect(420, 160, 32, 55));
        frameD0->setFrameShape(QFrame::StyledPanel);
        frameD0->setFrameShadow(QFrame::Raised);
        frameD1 = new QFrame(QMainForm);
        frameD1->setObjectName(QString::fromUtf8("frameD1"));
        frameD1->setGeometry(QRect(460, 160, 32, 55));
        frameD1->setFrameShape(QFrame::StyledPanel);
        frameD1->setFrameShadow(QFrame::Raised);
        frameD2 = new QFrame(QMainForm);
        frameD2->setObjectName(QString::fromUtf8("frameD2"));
        frameD2->setGeometry(QRect(500, 160, 32, 55));
        frameD2->setFrameShape(QFrame::StyledPanel);
        frameD2->setFrameShadow(QFrame::Raised);
        frameD3 = new QFrame(QMainForm);
        frameD3->setObjectName(QString::fromUtf8("frameD3"));
        frameD3->setGeometry(QRect(540, 160, 32, 55));
        frameD3->setFrameShape(QFrame::StyledPanel);
        frameD3->setFrameShadow(QFrame::Raised);
        frameD4 = new QFrame(QMainForm);
        frameD4->setObjectName(QString::fromUtf8("frameD4"));
        frameD4->setGeometry(QRect(590, 160, 32, 55));
        frameD4->setFrameShape(QFrame::StyledPanel);
        frameD4->setFrameShadow(QFrame::Raised);
        frameD5 = new QFrame(QMainForm);
        frameD5->setObjectName(QString::fromUtf8("frameD5"));
        frameD5->setGeometry(QRect(630, 160, 32, 55));
        frameD5->setFrameShape(QFrame::StyledPanel);
        frameD5->setFrameShadow(QFrame::Raised);
        frameD6 = new QFrame(QMainForm);
        frameD6->setObjectName(QString::fromUtf8("frameD6"));
        frameD6->setGeometry(QRect(670, 160, 32, 55));
        frameD6->setFrameShape(QFrame::StyledPanel);
        frameD6->setFrameShadow(QFrame::Raised);
        pushButtonTodo = new QPushButton(QMainForm);
        pushButtonTodo->setObjectName(QString::fromUtf8("pushButtonTodo"));
        pushButtonTodo->setGeometry(QRect(310, 220, 101, 41));
        pushButtonTodo->setStyleSheet(QString::fromUtf8("<font color=\\\"blue\\\">"));
        options->raise();
        frameOrig->raise();
        frameDest->raise();
        pushButtonCargar->raise();
        labelOrig->raise();
        labelDest->raise();
        pushButtonCopiarO->raise();
        pushButtonCopiarD->raise();
        pushButtonBorrar->raise();
        labelMat->raise();
        pushButtonSalir->raise();
        options_2->raise();
        options_3->raise();
        frameD0->raise();
        frameD1->raise();
        frameD2->raise();
        frameD3->raise();
        frameD4->raise();
        frameD5->raise();
        frameD6->raise();
        pushButtonTodo->raise();

        retranslateUi(QMainForm);

        QMetaObject::connectSlotsByName(QMainForm);
    } // setupUi

    void retranslateUi(QWidget *QMainForm)
    {
        QMainForm->setWindowTitle(QApplication::translate("QMainForm", "Detector de Matriculas AOC 2012-13", 0, QApplication::UnicodeUTF8));
        pushButtonCargar->setText(QApplication::translate("QMainForm", "Cargar", 0, QApplication::UnicodeUTF8));
        labelOrig->setText(QApplication::translate("QMainForm", "Matr\303\255cula ", 0, QApplication::UnicodeUTF8));
        labelDest->setText(QApplication::translate("QMainForm", "Matricula filtrada", 0, QApplication::UnicodeUTF8));
        pushButtonCopiarO->setText(QApplication::translate("QMainForm", ">>>", 0, QApplication::UnicodeUTF8));
        pushButtonCopiarD->setText(QApplication::translate("QMainForm", "<<<", 0, QApplication::UnicodeUTF8));
        pushButtonBorrar->setText(QApplication::translate("QMainForm", "Borrar", 0, QApplication::UnicodeUTF8));
        pushButtonNegar->setText(QApplication::translate("QMainForm", "Invertir Img.", 0, QApplication::UnicodeUTF8));
        pushButtonUmbralizar->setText(QApplication::translate("QMainForm", "Umbralizar Img.", 0, QApplication::UnicodeUTF8));
        labelMat->setText(QApplication::translate("QMainForm", "0000 XXX", 0, QApplication::UnicodeUTF8));
        pushButtonSalir->setText(QApplication::translate("QMainForm", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinUdetv->setToolTip(QApplication::translate("QMainForm", "umbral detecci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonDetectarH->setText(QApplication::translate("QMainForm", "Detectar Letras", 0, QApplication::UnicodeUTF8));
        pushButtonDetectarV->setText(QApplication::translate("QMainForm", "Det. Margen Vert.", 0, QApplication::UnicodeUTF8));
        labelDest_2->setText(QApplication::translate("QMainForm", "Umb. H.", 0, QApplication::UnicodeUTF8));
        labelDest_5->setText(QApplication::translate("QMainForm", "Umb. V.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinUdeth->setToolTip(QApplication::translate("QMainForm", "umbral detecci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinAncho->setToolTip(QApplication::translate("QMainForm", "umbral detecci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelDest_3->setText(QApplication::translate("QMainForm", "Ancho:", 0, QApplication::UnicodeUTF8));
        labelDest_4->setText(QApplication::translate("QMainForm", "Alto:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinAlto->setToolTip(QApplication::translate("QMainForm", "umbral detecci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonRecortar->setText(QApplication::translate("QMainForm", "Recortar", 0, QApplication::UnicodeUTF8));
        pushButtonMatching->setText(QApplication::translate("QMainForm", "Matching", 0, QApplication::UnicodeUTF8));
        pushButtonTodo->setText(QApplication::translate("QMainForm", "RECONOCER", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMainForm: public Ui_QMainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
