/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *configGroupBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *configWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *bitRateBox;
    QLabel *label_4;
    QComboBox *maxSizeBox;
    QLabel *label_6;
    QComboBox *formatBox;
    QWidget *configWidget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *lockOrientationBox;
    QSpacerItem *horizontalSpacer;
    QWidget *configWidget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *recordPathEdt;
    QPushButton *selectRecordPathBtn;
    QWidget *configWidget4;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *gameBox;
    QPushButton *refreshGameScriptBtn;
    QPushButton *applyScriptBtn;
    QWidget *configWidget3;
    QGridLayout *gridLayout;
    QCheckBox *closeScreenCheck;
    QCheckBox *framelessCheck;
    QCheckBox *alwaysTopCheck;
    QCheckBox *notDisplayCheck;
    QCheckBox *useReverseCheck;
    QCheckBox *recordScreenCheck;
    QCheckBox *fpsCheck;
    QCheckBox *stayAwakeCheck;
    QGroupBox *usbGroupBox;
    QVBoxLayout *verticalLayout;
    QWidget *usbWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *serialBox;
    QPushButton *startServerBtn;
    QPushButton *stopServerBtn;
    QWidget *usbWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *stopAllServerBtn;
    QPushButton *updateDevice;
    QPushButton *getIPBtn;
    QPushButton *startAdbdBtn;
    QGroupBox *wirelessGroupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *deviceIpEdt;
    QLabel *label;
    QLineEdit *devicePortEdt;
    QPushButton *wirelessConnectBtn;
    QPushButton *wirelessDisConnectBtn;
    QGroupBox *adbGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *adbCommandEdt;
    QPushButton *adbCommandBtn;
    QPushButton *stopAdbBtn;
    QPushButton *clearOut;
    QTextEdit *outEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(420, 607);
        Dialog->setMinimumSize(QSize(420, 0));
        Dialog->setMaximumSize(QSize(420, 16777215));
        Dialog->setWindowTitle(QString::fromUtf8("QtScrcpy"));
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        configGroupBox = new QGroupBox(Dialog);
        configGroupBox->setObjectName(QString::fromUtf8("configGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(configGroupBox->sizePolicy().hasHeightForWidth());
        configGroupBox->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(configGroupBox);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        configWidget1 = new QWidget(configGroupBox);
        configWidget1->setObjectName(QString::fromUtf8("configWidget1"));
        horizontalLayout_5 = new QHBoxLayout(configWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(configWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        bitRateBox = new QComboBox(configWidget1);
        bitRateBox->setObjectName(QString::fromUtf8("bitRateBox"));

        horizontalLayout_5->addWidget(bitRateBox);

        label_4 = new QLabel(configWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        maxSizeBox = new QComboBox(configWidget1);
        maxSizeBox->setObjectName(QString::fromUtf8("maxSizeBox"));

        horizontalLayout_5->addWidget(maxSizeBox);

        label_6 = new QLabel(configWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        formatBox = new QComboBox(configWidget1);
        formatBox->setObjectName(QString::fromUtf8("formatBox"));

        horizontalLayout_5->addWidget(formatBox);


        verticalLayout_3->addWidget(configWidget1);

        configWidget5 = new QWidget(configGroupBox);
        configWidget5->setObjectName(QString::fromUtf8("configWidget5"));
        horizontalLayout_7 = new QHBoxLayout(configWidget5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(configWidget5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        lockOrientationBox = new QComboBox(configWidget5);
        lockOrientationBox->setObjectName(QString::fromUtf8("lockOrientationBox"));

        horizontalLayout_7->addWidget(lockOrientationBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(configWidget5);

        configWidget2 = new QWidget(configGroupBox);
        configWidget2->setObjectName(QString::fromUtf8("configWidget2"));
        horizontalLayout_6 = new QHBoxLayout(configWidget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(configWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        recordPathEdt = new QLineEdit(configWidget2);
        recordPathEdt->setObjectName(QString::fromUtf8("recordPathEdt"));
        recordPathEdt->setReadOnly(true);

        horizontalLayout_6->addWidget(recordPathEdt);

        selectRecordPathBtn = new QPushButton(configWidget2);
        selectRecordPathBtn->setObjectName(QString::fromUtf8("selectRecordPathBtn"));
        selectRecordPathBtn->setAutoDefault(false);

        horizontalLayout_6->addWidget(selectRecordPathBtn);


        verticalLayout_3->addWidget(configWidget2);

        configWidget4 = new QWidget(configGroupBox);
        configWidget4->setObjectName(QString::fromUtf8("configWidget4"));
        horizontalLayout_8 = new QHBoxLayout(configWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        gameBox = new QComboBox(configWidget4);
        gameBox->setObjectName(QString::fromUtf8("gameBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gameBox->sizePolicy().hasHeightForWidth());
        gameBox->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(gameBox);

        refreshGameScriptBtn = new QPushButton(configWidget4);
        refreshGameScriptBtn->setObjectName(QString::fromUtf8("refreshGameScriptBtn"));

        horizontalLayout_8->addWidget(refreshGameScriptBtn);

        applyScriptBtn = new QPushButton(configWidget4);
        applyScriptBtn->setObjectName(QString::fromUtf8("applyScriptBtn"));

        horizontalLayout_8->addWidget(applyScriptBtn);


        verticalLayout_3->addWidget(configWidget4);

        configWidget3 = new QWidget(configGroupBox);
        configWidget3->setObjectName(QString::fromUtf8("configWidget3"));
        gridLayout = new QGridLayout(configWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        closeScreenCheck = new QCheckBox(configWidget3);
        closeScreenCheck->setObjectName(QString::fromUtf8("closeScreenCheck"));
        sizePolicy1.setHeightForWidth(closeScreenCheck->sizePolicy().hasHeightForWidth());
        closeScreenCheck->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(closeScreenCheck, 1, 1, 1, 1);

        framelessCheck = new QCheckBox(configWidget3);
        framelessCheck->setObjectName(QString::fromUtf8("framelessCheck"));

        gridLayout->addWidget(framelessCheck, 1, 3, 1, 1);

        alwaysTopCheck = new QCheckBox(configWidget3);
        alwaysTopCheck->setObjectName(QString::fromUtf8("alwaysTopCheck"));
        sizePolicy1.setHeightForWidth(alwaysTopCheck->sizePolicy().hasHeightForWidth());
        alwaysTopCheck->setSizePolicy(sizePolicy1);
        alwaysTopCheck->setChecked(false);

        gridLayout->addWidget(alwaysTopCheck, 1, 0, 1, 1);

        notDisplayCheck = new QCheckBox(configWidget3);
        notDisplayCheck->setObjectName(QString::fromUtf8("notDisplayCheck"));
        sizePolicy1.setHeightForWidth(notDisplayCheck->sizePolicy().hasHeightForWidth());
        notDisplayCheck->setSizePolicy(sizePolicy1);
        notDisplayCheck->setCheckable(false);

        gridLayout->addWidget(notDisplayCheck, 0, 1, 1, 1);

        useReverseCheck = new QCheckBox(configWidget3);
        useReverseCheck->setObjectName(QString::fromUtf8("useReverseCheck"));
        sizePolicy1.setHeightForWidth(useReverseCheck->sizePolicy().hasHeightForWidth());
        useReverseCheck->setSizePolicy(sizePolicy1);
        useReverseCheck->setChecked(true);

        gridLayout->addWidget(useReverseCheck, 0, 3, 1, 1);

        recordScreenCheck = new QCheckBox(configWidget3);
        recordScreenCheck->setObjectName(QString::fromUtf8("recordScreenCheck"));

        gridLayout->addWidget(recordScreenCheck, 0, 0, 1, 1);

        fpsCheck = new QCheckBox(configWidget3);
        fpsCheck->setObjectName(QString::fromUtf8("fpsCheck"));

        gridLayout->addWidget(fpsCheck, 0, 4, 1, 1);

        stayAwakeCheck = new QCheckBox(configWidget3);
        stayAwakeCheck->setObjectName(QString::fromUtf8("stayAwakeCheck"));

        gridLayout->addWidget(stayAwakeCheck, 1, 4, 1, 1);


        verticalLayout_3->addWidget(configWidget3);


        verticalLayout_2->addWidget(configGroupBox);

        usbGroupBox = new QGroupBox(Dialog);
        usbGroupBox->setObjectName(QString::fromUtf8("usbGroupBox"));
        sizePolicy.setHeightForWidth(usbGroupBox->sizePolicy().hasHeightForWidth());
        usbGroupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(usbGroupBox);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        usbWidget1 = new QWidget(usbGroupBox);
        usbWidget1->setObjectName(QString::fromUtf8("usbWidget1"));
        horizontalLayout_3 = new QHBoxLayout(usbWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(usbWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        serialBox = new QComboBox(usbWidget1);
        serialBox->setObjectName(QString::fromUtf8("serialBox"));

        horizontalLayout_3->addWidget(serialBox);

        startServerBtn = new QPushButton(usbWidget1);
        startServerBtn->setObjectName(QString::fromUtf8("startServerBtn"));
        startServerBtn->setAutoDefault(false);

        horizontalLayout_3->addWidget(startServerBtn);

        stopServerBtn = new QPushButton(usbWidget1);
        stopServerBtn->setObjectName(QString::fromUtf8("stopServerBtn"));
        stopServerBtn->setAutoDefault(false);

        horizontalLayout_3->addWidget(stopServerBtn);


        verticalLayout->addWidget(usbWidget1);

        usbWidget2 = new QWidget(usbGroupBox);
        usbWidget2->setObjectName(QString::fromUtf8("usbWidget2"));
        horizontalLayout_4 = new QHBoxLayout(usbWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        stopAllServerBtn = new QPushButton(usbWidget2);
        stopAllServerBtn->setObjectName(QString::fromUtf8("stopAllServerBtn"));

        horizontalLayout_4->addWidget(stopAllServerBtn);

        updateDevice = new QPushButton(usbWidget2);
        updateDevice->setObjectName(QString::fromUtf8("updateDevice"));
        updateDevice->setAutoDefault(false);

        horizontalLayout_4->addWidget(updateDevice);

        getIPBtn = new QPushButton(usbWidget2);
        getIPBtn->setObjectName(QString::fromUtf8("getIPBtn"));
        getIPBtn->setAutoDefault(false);

        horizontalLayout_4->addWidget(getIPBtn);

        startAdbdBtn = new QPushButton(usbWidget2);
        startAdbdBtn->setObjectName(QString::fromUtf8("startAdbdBtn"));
        startAdbdBtn->setAutoDefault(false);

        horizontalLayout_4->addWidget(startAdbdBtn);


        verticalLayout->addWidget(usbWidget2);


        verticalLayout_2->addWidget(usbGroupBox);

        wirelessGroupBox = new QGroupBox(Dialog);
        wirelessGroupBox->setObjectName(QString::fromUtf8("wirelessGroupBox"));
        sizePolicy.setHeightForWidth(wirelessGroupBox->sizePolicy().hasHeightForWidth());
        wirelessGroupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(wirelessGroupBox);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        deviceIpEdt = new QLineEdit(wirelessGroupBox);
        deviceIpEdt->setObjectName(QString::fromUtf8("deviceIpEdt"));
        deviceIpEdt->setMaxLength(128);
        deviceIpEdt->setPlaceholderText(QString::fromUtf8("192.168.0.1"));

        horizontalLayout->addWidget(deviceIpEdt);

        label = new QLabel(wirelessGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(5, 0));
        label->setMaximumSize(QSize(5, 16777215));
        label->setText(QString::fromUtf8(":"));

        horizontalLayout->addWidget(label);

        devicePortEdt = new QLineEdit(wirelessGroupBox);
        devicePortEdt->setObjectName(QString::fromUtf8("devicePortEdt"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(devicePortEdt->sizePolicy().hasHeightForWidth());
        devicePortEdt->setSizePolicy(sizePolicy2);
        devicePortEdt->setMaximumSize(QSize(60, 16777215));
        devicePortEdt->setMaxLength(6);
        devicePortEdt->setPlaceholderText(QString::fromUtf8("5555"));

        horizontalLayout->addWidget(devicePortEdt);

        wirelessConnectBtn = new QPushButton(wirelessGroupBox);
        wirelessConnectBtn->setObjectName(QString::fromUtf8("wirelessConnectBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(wirelessConnectBtn->sizePolicy().hasHeightForWidth());
        wirelessConnectBtn->setSizePolicy(sizePolicy3);
        wirelessConnectBtn->setAutoDefault(false);

        horizontalLayout->addWidget(wirelessConnectBtn);

        wirelessDisConnectBtn = new QPushButton(wirelessGroupBox);
        wirelessDisConnectBtn->setObjectName(QString::fromUtf8("wirelessDisConnectBtn"));
        sizePolicy3.setHeightForWidth(wirelessDisConnectBtn->sizePolicy().hasHeightForWidth());
        wirelessDisConnectBtn->setSizePolicy(sizePolicy3);
        wirelessDisConnectBtn->setAutoDefault(false);

        horizontalLayout->addWidget(wirelessDisConnectBtn);


        verticalLayout_2->addWidget(wirelessGroupBox);

        adbGroupBox = new QGroupBox(Dialog);
        adbGroupBox->setObjectName(QString::fromUtf8("adbGroupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(adbGroupBox->sizePolicy().hasHeightForWidth());
        adbGroupBox->setSizePolicy(sizePolicy4);
        adbGroupBox->setTitle(QString::fromUtf8("adb"));
        horizontalLayout_2 = new QHBoxLayout(adbGroupBox);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(adbGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        adbCommandEdt = new QLineEdit(adbGroupBox);
        adbCommandEdt->setObjectName(QString::fromUtf8("adbCommandEdt"));
        adbCommandEdt->setText(QString::fromUtf8("devices"));

        horizontalLayout_2->addWidget(adbCommandEdt);

        adbCommandBtn = new QPushButton(adbGroupBox);
        adbCommandBtn->setObjectName(QString::fromUtf8("adbCommandBtn"));
        sizePolicy3.setHeightForWidth(adbCommandBtn->sizePolicy().hasHeightForWidth());
        adbCommandBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(adbCommandBtn);

        stopAdbBtn = new QPushButton(adbGroupBox);
        stopAdbBtn->setObjectName(QString::fromUtf8("stopAdbBtn"));
        sizePolicy3.setHeightForWidth(stopAdbBtn->sizePolicy().hasHeightForWidth());
        stopAdbBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(stopAdbBtn);

        clearOut = new QPushButton(adbGroupBox);
        clearOut->setObjectName(QString::fromUtf8("clearOut"));
        sizePolicy3.setHeightForWidth(clearOut->sizePolicy().hasHeightForWidth());
        clearOut->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(clearOut);


        verticalLayout_2->addWidget(adbGroupBox);

        outEdit = new QTextEdit(Dialog);
        outEdit->setObjectName(QString::fromUtf8("outEdit"));
        sizePolicy1.setHeightForWidth(outEdit->sizePolicy().hasHeightForWidth());
        outEdit->setSizePolicy(sizePolicy1);
        outEdit->setMinimumSize(QSize(0, 140));
        outEdit->setFocusPolicy(Qt::ClickFocus);
        outEdit->setReadOnly(true);

        verticalLayout_2->addWidget(outEdit);

#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(recordPathEdt);
        label_7->setBuddy(adbCommandEdt);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(deviceIpEdt, devicePortEdt);
        QWidget::setTabOrder(devicePortEdt, wirelessConnectBtn);
        QWidget::setTabOrder(wirelessConnectBtn, wirelessDisConnectBtn);
        QWidget::setTabOrder(wirelessDisConnectBtn, adbCommandEdt);
        QWidget::setTabOrder(adbCommandEdt, adbCommandBtn);
        QWidget::setTabOrder(adbCommandBtn, stopAdbBtn);
        QWidget::setTabOrder(stopAdbBtn, clearOut);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        configGroupBox->setTitle(QApplication::translate("Dialog", "Start Config", nullptr));
        label_3->setText(QApplication::translate("Dialog", "bit rate:", nullptr));
#ifndef QT_NO_TOOLTIP
        bitRateBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bitRateBox->setCurrentText(QString());
        label_4->setText(QApplication::translate("Dialog", "max size:", nullptr));
#ifndef QT_NO_TOOLTIP
        maxSizeBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Dialog", "record format\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Dialog", "lock orientation:", nullptr));
        label_5->setText(QApplication::translate("Dialog", "record save path:", nullptr));
        selectRecordPathBtn->setText(QApplication::translate("Dialog", "select path", nullptr));
        refreshGameScriptBtn->setText(QApplication::translate("Dialog", "refresh script", nullptr));
        applyScriptBtn->setText(QApplication::translate("Dialog", "apply", nullptr));
        closeScreenCheck->setText(QApplication::translate("Dialog", "screen-off", nullptr));
        framelessCheck->setText(QApplication::translate("Dialog", "frameless", nullptr));
        alwaysTopCheck->setText(QApplication::translate("Dialog", "always on top", nullptr));
        notDisplayCheck->setText(QApplication::translate("Dialog", "background record", nullptr));
        useReverseCheck->setText(QApplication::translate("Dialog", "reverse connection", nullptr));
        recordScreenCheck->setText(QApplication::translate("Dialog", "record screen", nullptr));
        fpsCheck->setText(QApplication::translate("Dialog", "show fps", nullptr));
        stayAwakeCheck->setText(QApplication::translate("Dialog", "stay awake", nullptr));
        usbGroupBox->setTitle(QApplication::translate("Dialog", "USB line", nullptr));
        label_2->setText(QApplication::translate("Dialog", "device serial:", nullptr));
        startServerBtn->setText(QApplication::translate("Dialog", "start server", nullptr));
        stopServerBtn->setText(QApplication::translate("Dialog", "stop server", nullptr));
        stopAllServerBtn->setText(QApplication::translate("Dialog", "stop all server", nullptr));
        updateDevice->setText(QApplication::translate("Dialog", "refresh devices", nullptr));
        getIPBtn->setText(QApplication::translate("Dialog", "get device IP", nullptr));
        startAdbdBtn->setText(QApplication::translate("Dialog", "start adbd", nullptr));
        wirelessGroupBox->setTitle(QApplication::translate("Dialog", "Wireless", nullptr));
        deviceIpEdt->setText(QString());
        devicePortEdt->setText(QString());
        wirelessConnectBtn->setText(QApplication::translate("Dialog", "wireless connect", nullptr));
        wirelessDisConnectBtn->setText(QApplication::translate("Dialog", "wireless disconnect", nullptr));
        label_7->setText(QApplication::translate("Dialog", "adb command:", nullptr));
        adbCommandBtn->setText(QApplication::translate("Dialog", "execute", nullptr));
        stopAdbBtn->setText(QApplication::translate("Dialog", "terminate", nullptr));
        clearOut->setText(QApplication::translate("Dialog", "clear", nullptr));
        outEdit->setDocumentTitle(QString());
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
