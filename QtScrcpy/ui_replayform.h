/********************************************************************************
** Form generated from reading UI file 'replayform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYFORM_H
#define UI_REPLAYFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replayform
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *savePathEdit;
    QPushButton *savePathButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *sleepTimeEdit;
    QPushButton *insertSleepButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startRecordButton;
    QPushButton *stopRecordButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *replayFileEdit;
    QPushButton *replayFileButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *replayCountEdit;
    QPushButton *startReplayButton;
    QPushButton *pauseButton;
    QPushButton *stopReplayButton;
    QCheckBox *checkBox;
    QTextEdit *logEdit;
    QLabel *label_3;
    QLabel *imageLabel;
    QLabel *windowNameLabel;
    QSlider *sliderProgress;

    void setupUi(QWidget *replayform)
    {
        if (replayform->objectName().isEmpty())
            replayform->setObjectName(QString::fromUtf8("replayform"));
        replayform->resize(414, 618);
        replayform->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        verticalLayout = new QVBoxLayout(replayform);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 30, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        savePathEdit = new QLineEdit(replayform);
        savePathEdit->setObjectName(QString::fromUtf8("savePathEdit"));

        horizontalLayout->addWidget(savePathEdit);

        savePathButton = new QPushButton(replayform);
        savePathButton->setObjectName(QString::fromUtf8("savePathButton"));

        horizontalLayout->addWidget(savePathButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(replayform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        sleepTimeEdit = new QLineEdit(replayform);
        sleepTimeEdit->setObjectName(QString::fromUtf8("sleepTimeEdit"));

        horizontalLayout_5->addWidget(sleepTimeEdit);

        insertSleepButton = new QPushButton(replayform);
        insertSleepButton->setObjectName(QString::fromUtf8("insertSleepButton"));

        horizontalLayout_5->addWidget(insertSleepButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        startRecordButton = new QPushButton(replayform);
        startRecordButton->setObjectName(QString::fromUtf8("startRecordButton"));

        horizontalLayout_2->addWidget(startRecordButton);

        stopRecordButton = new QPushButton(replayform);
        stopRecordButton->setObjectName(QString::fromUtf8("stopRecordButton"));

        horizontalLayout_2->addWidget(stopRecordButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        replayFileEdit = new QLineEdit(replayform);
        replayFileEdit->setObjectName(QString::fromUtf8("replayFileEdit"));

        horizontalLayout_3->addWidget(replayFileEdit);

        replayFileButton = new QPushButton(replayform);
        replayFileButton->setObjectName(QString::fromUtf8("replayFileButton"));

        horizontalLayout_3->addWidget(replayFileButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(replayform);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        replayCountEdit = new QLineEdit(replayform);
        replayCountEdit->setObjectName(QString::fromUtf8("replayCountEdit"));

        horizontalLayout_4->addWidget(replayCountEdit);

        startReplayButton = new QPushButton(replayform);
        startReplayButton->setObjectName(QString::fromUtf8("startReplayButton"));

        horizontalLayout_4->addWidget(startReplayButton);

        pauseButton = new QPushButton(replayform);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_4->addWidget(pauseButton);

        stopReplayButton = new QPushButton(replayform);
        stopReplayButton->setObjectName(QString::fromUtf8("stopReplayButton"));

        horizontalLayout_4->addWidget(stopReplayButton);


        verticalLayout->addLayout(horizontalLayout_4);

        checkBox = new QCheckBox(replayform);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        logEdit = new QTextEdit(replayform);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));
        logEdit->setReadOnly(true);

        verticalLayout->addWidget(logEdit);

        label_3 = new QLabel(replayform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        imageLabel = new QLabel(replayform);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setMinimumSize(QSize(100, 200));

        verticalLayout->addWidget(imageLabel, 0, Qt::AlignHCenter);

        windowNameLabel = new QLabel(replayform);
        windowNameLabel->setObjectName(QString::fromUtf8("windowNameLabel"));

        verticalLayout->addWidget(windowNameLabel);

        sliderProgress = new QSlider(replayform);
        sliderProgress->setObjectName(QString::fromUtf8("sliderProgress"));
        sliderProgress->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliderProgress);


        retranslateUi(replayform);

        QMetaObject::connectSlotsByName(replayform);
    } // setupUi

    void retranslateUi(QWidget *replayform)
    {
        replayform->setWindowTitle(QApplication::translate("replayform", "Replay", nullptr));
        savePathButton->setText(QApplication::translate("replayform", "\351\200\211\346\213\251\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        label_2->setText(QApplication::translate("replayform", "\346\223\215\344\275\234\351\227\264\351\232\224\346\227\266\351\227\264\357\274\210\345\215\225\344\275\215/\347\247\222\357\274\211\357\274\232", nullptr));
        insertSleepButton->setText(QApplication::translate("replayform", "\346\217\222\345\205\245\346\227\266\351\227\264", nullptr));
        startRecordButton->setText(QApplication::translate("replayform", "\345\274\200\345\247\213\345\275\225\345\210\266", nullptr));
        stopRecordButton->setText(QApplication::translate("replayform", "\347\273\223\346\235\237\345\275\225\345\210\266", nullptr));
        replayFileButton->setText(QApplication::translate("replayform", "\351\200\211\346\213\251\345\233\236\346\224\276\346\226\207\344\273\266", nullptr));
        label->setText(QApplication::translate("replayform", "\345\233\236\346\224\276\346\254\241\346\225\260\357\274\232", nullptr));
        startReplayButton->setText(QApplication::translate("replayform", "\345\274\200\345\247\213\345\233\236\346\224\276", nullptr));
        pauseButton->setText(QApplication::translate("replayform", "\346\232\202\345\201\234\345\233\236\346\224\276", nullptr));
        stopReplayButton->setText(QApplication::translate("replayform", "\345\201\234\346\255\242\345\233\236\346\224\276", nullptr));
        checkBox->setText(QApplication::translate("replayform", "\345\234\250\346\213\226\345\212\250\347\232\204\350\277\233\345\272\246\344\275\215\347\275\256\346\201\242\345\244\215\345\233\236\346\224\276", nullptr));
        label_3->setText(QApplication::translate("replayform", "\346\263\250\346\204\217\357\274\232\345\233\236\346\224\276\346\213\226\345\212\250\346\265\213\350\257\225\347\232\204APP Icon\345\217\252\350\203\275\346\224\276\345\234\250launcher\347\254\254\344\270\200\345\261\217", nullptr));
        imageLabel->setText(QString());
        windowNameLabel->setText(QApplication::translate("replayform", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replayform: public Ui_replayform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYFORM_H
