/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnSaveBMP;
    QPushButton *btnSaveJPG;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnSaveTIFF;
    QPushButton *btnSavePNG;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartGrab;
    QPushButton *btnStopGrab;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QPlainTextEdit *B_light;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QPlainTextEdit *B__expose;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QPlainTextEdit *B__gamma_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QPlainTextEdit *B__fps;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *B_getParam;
    QPushButton *B_setParam;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_Gamma;
    QPlainTextEdit *B__Gamma;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *B_getGamma;
    QPushButton *B_setGamma;
    QPushButton *btnCloseWin;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *BdEdit;
    QPushButton *btnGetImage;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *featureline;
    QPushButton *btnFeature;
    QPlainTextEdit *label_233;
    QLabel *label_5;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QPlainTextEdit *B_H;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QPlainTextEdit *B_S;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QPlainTextEdit *B_V;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1114, 609);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 431, 441));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image:url(2.jpg);\n"
"border:5px solid red;\n"
"border-image:url(2.jpg);\n"
"}\n"
""));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(890, 70, 221, 106));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnSaveBMP = new QPushButton(groupBox_3);
        btnSaveBMP->setObjectName(QString::fromUtf8("btnSaveBMP"));
        btnSaveBMP->setMinimumSize(QSize(100, 30));
        btnSaveBMP->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(btnSaveBMP);

        btnSaveJPG = new QPushButton(groupBox_3);
        btnSaveJPG->setObjectName(QString::fromUtf8("btnSaveJPG"));
        btnSaveJPG->setMinimumSize(QSize(100, 30));
        btnSaveJPG->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(btnSaveJPG);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnSaveTIFF = new QPushButton(groupBox_3);
        btnSaveTIFF->setObjectName(QString::fromUtf8("btnSaveTIFF"));
        btnSaveTIFF->setMinimumSize(QSize(100, 30));
        btnSaveTIFF->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(btnSaveTIFF);

        btnSavePNG = new QPushButton(groupBox_3);
        btnSavePNG->setObjectName(QString::fromUtf8("btnSavePNG"));
        btnSavePNG->setMinimumSize(QSize(100, 30));
        btnSavePNG->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(btnSavePNG);


        verticalLayout_3->addLayout(horizontalLayout_5);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(890, 0, 221, 68));
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 208, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnStartGrab = new QPushButton(layoutWidget);
        btnStartGrab->setObjectName(QString::fromUtf8("btnStartGrab"));
        btnStartGrab->setMinimumSize(QSize(100, 30));
        btnStartGrab->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 255);"));

        horizontalLayout->addWidget(btnStartGrab);

        btnStopGrab = new QPushButton(layoutWidget);
        btnStopGrab->setObjectName(QString::fromUtf8("btnStopGrab"));
        btnStopGrab->setMinimumSize(QSize(100, 30));
        btnStopGrab->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 255);"));

        horizontalLayout->addWidget(btnStopGrab);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(890, 180, 228, 221));
        groupBox_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 255, 174);"));

        horizontalLayout_2->addWidget(label_6);

        B_light = new QPlainTextEdit(groupBox_5);
        B_light->setObjectName(QString::fromUtf8("B_light"));
        B_light->setStyleSheet(QString::fromUtf8("background-color: rgb(255,155, 55);"));

        horizontalLayout_2->addWidget(B_light);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(155, 255, 174);"));

        horizontalLayout_7->addWidget(label_2);

        B__expose = new QPlainTextEdit(groupBox_5);
        B__expose->setObjectName(QString::fromUtf8("B__expose"));
        B__expose->setMaximumSize(QSize(150, 30));
        B__expose->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 155, 55);"));

        horizontalLayout_7->addWidget(B__expose);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 174);"));

        horizontalLayout_8->addWidget(label_3);

        B__gamma_2 = new QPlainTextEdit(groupBox_5);
        B__gamma_2->setObjectName(QString::fromUtf8("B__gamma_2"));
        B__gamma_2->setMaximumSize(QSize(150, 30));
        B__gamma_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 255);"));

        horizontalLayout_8->addWidget(B__gamma_2);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 74);"));

        horizontalLayout_9->addWidget(label_4);

        B__fps = new QPlainTextEdit(groupBox_5);
        B__fps->setObjectName(QString::fromUtf8("B__fps"));
        B__fps->setMaximumSize(QSize(150, 30));
        B__fps->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 55, 255);"));

        horizontalLayout_9->addWidget(B__fps);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        B_getParam = new QPushButton(groupBox_5);
        B_getParam->setObjectName(QString::fromUtf8("B_getParam"));
        B_getParam->setMinimumSize(QSize(100, 30));
        B_getParam->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 155, 255);"));

        horizontalLayout_6->addWidget(B_getParam);

        B_setParam = new QPushButton(groupBox_5);
        B_setParam->setObjectName(QString::fromUtf8("B_setParam"));
        B_setParam->setMinimumSize(QSize(100, 30));
        B_setParam->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 155, 255);"));

        horizontalLayout_6->addWidget(B_setParam);


        verticalLayout->addLayout(horizontalLayout_6);

        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(890, 400, 221, 101));
        groupBox_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupBox_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_Gamma = new QLabel(groupBox_6);
        label_Gamma->setObjectName(QString::fromUtf8("label_Gamma"));
        label_Gamma->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 174);"));

        horizontalLayout_10->addWidget(label_Gamma);

        B__Gamma = new QPlainTextEdit(groupBox_6);
        B__Gamma->setObjectName(QString::fromUtf8("B__Gamma"));
        B__Gamma->setMaximumSize(QSize(150, 30));
        B__Gamma->setStyleSheet(QString::fromUtf8("background-color: rgb(155, 55, 255);"));

        horizontalLayout_10->addWidget(B__Gamma);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        B_getGamma = new QPushButton(groupBox_6);
        B_getGamma->setObjectName(QString::fromUtf8("B_getGamma"));
        B_getGamma->setMinimumSize(QSize(100, 30));
        B_getGamma->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 55);"));

        horizontalLayout_13->addWidget(B_getGamma);

        B_setGamma = new QPushButton(groupBox_6);
        B_setGamma->setObjectName(QString::fromUtf8("B_setGamma"));
        B_setGamma->setMinimumSize(QSize(100, 30));
        B_setGamma->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 255);"));

        horizontalLayout_13->addWidget(B_setGamma);


        verticalLayout_2->addLayout(horizontalLayout_13);

        btnCloseWin = new QPushButton(Widget);
        btnCloseWin->setObjectName(QString::fromUtf8("btnCloseWin"));
        btnCloseWin->setGeometry(QRect(1010, 570, 100, 30));
        btnCloseWin->setMinimumSize(QSize(100, 30));
        btnCloseWin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 55, 255);"));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1009, 500, 101, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        BdEdit = new QLineEdit(verticalLayoutWidget);
        BdEdit->setObjectName(QString::fromUtf8("BdEdit"));

        verticalLayout_4->addWidget(BdEdit);

        btnGetImage = new QPushButton(verticalLayoutWidget);
        btnGetImage->setObjectName(QString::fromUtf8("btnGetImage"));

        verticalLayout_4->addWidget(btnGetImage);

        verticalLayoutWidget_2 = new QWidget(Widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(889, 500, 121, 61));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        featureline = new QLineEdit(verticalLayoutWidget_2);
        featureline->setObjectName(QString::fromUtf8("featureline"));

        verticalLayout_5->addWidget(featureline);

        btnFeature = new QPushButton(verticalLayoutWidget_2);
        btnFeature->setObjectName(QString::fromUtf8("btnFeature"));

        verticalLayout_5->addWidget(btnFeature);

        label_233 = new QPlainTextEdit(Widget);
        label_233->setObjectName(QString::fromUtf8("label_233"));
        label_233->setGeometry(QRect(30, 520, 421, 87));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 10, 401, 441));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image:url(1.jpg);\n"
"border:5px solid red;\n"
"border-image:url(1.jpg);\n"
"}\n"
""));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(900, 570, 101, 31));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(570, 480, 191, 111));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 160, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        B_H = new QPlainTextEdit(horizontalLayoutWidget);
        B_H->setObjectName(QString::fromUtf8("B_H"));

        horizontalLayout_3->addWidget(B_H);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 50, 160, 21));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        B_S = new QPlainTextEdit(horizontalLayoutWidget_2);
        B_S->setObjectName(QString::fromUtf8("B_S"));

        horizontalLayout_11->addWidget(B_S);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 80, 160, 21));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        B_V = new QPlainTextEdit(horizontalLayoutWidget_3);
        B_V->setObjectName(QString::fromUtf8("B_V"));

        horizontalLayout_12->addWidget(B_V);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "ImageSave", nullptr));
#if QT_CONFIG(tooltip)
        btnSaveBMP->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSaveBMP->setText(QCoreApplication::translate("Widget", "BMP", nullptr));
#if QT_CONFIG(tooltip)
        btnSaveJPG->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSaveJPG->setText(QCoreApplication::translate("Widget", "JPG", nullptr));
#if QT_CONFIG(tooltip)
        btnSaveTIFF->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSaveTIFF->setText(QCoreApplication::translate("Widget", "TIFF", nullptr));
#if QT_CONFIG(tooltip)
        btnSavePNG->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSavePNG->setText(QCoreApplication::translate("Widget", "PNG", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "ImageGrab", nullptr));
#if QT_CONFIG(tooltip)
        btnStartGrab->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStartGrab->setText(QCoreApplication::translate("Widget", "Start", nullptr));
#if QT_CONFIG(tooltip)
        btnStopGrab->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStopGrab->setText(QCoreApplication::translate("Widget", "Stop", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\344\272\256\345\272\246", nullptr));
        B_light->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\344\272\256\345\272\246\345\200\274", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\233\235\345\205\211", nullptr));
        B__expose->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\346\233\235\345\205\211\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\242\236\347\233\212", nullptr));
        B__gamma_2->setPlaceholderText(QCoreApplication::translate("Widget", "\345\217\226\345\200\274\350\214\203\345\233\264\357\274\2320~15", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\270\247\347\216\207", nullptr));
        B__fps->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\270\247\347\216\207\345\200\274", nullptr));
#if QT_CONFIG(tooltip)
        B_getParam->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        B_getParam->setText(QCoreApplication::translate("Widget", "\345\217\202\346\225\260\350\216\267\345\217\226", nullptr));
#if QT_CONFIG(tooltip)
        B_setParam->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        B_setParam->setText(QCoreApplication::translate("Widget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Widget", "Gamma\346\240\241\346\255\243", nullptr));
        label_Gamma->setText(QCoreApplication::translate("Widget", "Gamma", nullptr));
        B__Gamma->setPlaceholderText(QCoreApplication::translate("Widget", "\345\217\226\345\200\274\350\214\203\345\233\264\357\274\2320~4", nullptr));
#if QT_CONFIG(tooltip)
        B_getGamma->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        B_getGamma->setText(QCoreApplication::translate("Widget", "\345\217\202\346\225\260\350\216\267\345\217\226", nullptr));
#if QT_CONFIG(tooltip)
        B_setGamma->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        B_setGamma->setText(QCoreApplication::translate("Widget", "Gamma\346\240\241\346\255\243", nullptr));
#if QT_CONFIG(tooltip)
        btnCloseWin->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCloseWin->setText(QCoreApplication::translate("Widget", "Shut", nullptr));
        btnGetImage->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232\346\240\207\345\256\232\346\226\207\344\273\266", nullptr));
        btnFeature->setText(QCoreApplication::translate("Widget", "\347\211\271\345\276\201\346\217\220\345\217\226", nullptr));
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "faccedect", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "HSV\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Hue", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Saturation", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
