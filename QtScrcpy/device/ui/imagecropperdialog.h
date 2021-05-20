#ifndef IMAGECROPPERDIALOG_H
#define IMAGECROPPERDIALOG_H
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDesktopWidget>
#include <QScreen>
#include <QGuiApplication>

#include "imagecropperlabel.h"

/*******************************************************
 *  Loacl private class, which do image-cropping
 *  Used in class ImageCropper
*******************************************************/
class ImageCropperDialogPrivate : public QDialog {
    Q_OBJECT
public:
    ImageCropperDialogPrivate(const QPixmap& imageIn, QRect& outputImage,
                              int windowWidth, int windowHeight,
                              CropperShape shape, QSize cropperSize = QSize()) :
        QDialog(nullptr),  outputImage(outputImage)
    {
        this->setAttribute(Qt::WA_DeleteOnClose, true);
        this->setWindowTitle("添加校验点");
        this->setMouseTracking(true);
        this->setModal(true);
        imageLabel = new ImageCropperLabel(windowWidth, windowHeight, this);
        imageLabel->setCropper(shape, cropperSize);
        imageLabel->setOutputShape(OutputShape::RECT);
        imageLabel->setOriginalImage(imageIn);
        imageLabel->enableOpacity(true);
        defOut = imageLabel->getDefCrop();
        QHBoxLayout* btnLayout = new QHBoxLayout();
        btnOk = new QPushButton("OK", this);
        btnCancel = new QPushButton("Cancel", this);
        btnLayout->addStretch();
        btnLayout->addWidget(btnOk);
        btnLayout->addWidget(btnCancel);

        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(imageLabel);
        mainLayout->addLayout(btnLayout);

        connect(btnOk, &QPushButton::clicked, this, [this](){
            this->outputImage = this->imageLabel->getCroppedImage();
            this->close();
        });
        connect(btnCancel, &QPushButton::clicked, this, [this](){
            this->outputImage = this->imageLabel->getDefCrop();
            this->close();
        });
    }

private:
    ImageCropperLabel* imageLabel;
    QPushButton* btnOk;
    QPushButton* btnCancel;
    QRect& outputImage;
    QRect defOut;
};


/*******************************************************************
 *  class ImageCropperDialog
 *      create a instane of class ImageCropperDialogPrivate
 *      and get cropped image from the instance(after closing)
********************************************************************/
class ImageCropperDialog : QObject {
public:
    static QRect getCroppedImage(const QString& filename,
                                   CropperShape cropperShape, QSize crooperSize = QSize())
    {
        QPixmap inputImage;

        if (!inputImage.load(filename)) {
            QMessageBox::critical(nullptr, "Error", "Load image failed!", QMessageBox::Ok);
            return QRect();
        }
        QScreen* pDesktopWidget = QGuiApplication::primaryScreen();
        QRect deskRect = pDesktopWidget->availableGeometry();

        double scale = double(inputImage.size().width()) / double(inputImage.size().height());
        qInfo() << "size :" << inputImage.size().width() << "," << inputImage.size().height() << " scale " << scale;
        int windowHeight = deskRect.height() * 0.8;
        int windowWidth = windowHeight * scale;


        QRect outputImage = QRect(0,0,windowWidth,windowHeight);
        ImageCropperDialogPrivate* imageCropperDo =
            new ImageCropperDialogPrivate(inputImage, outputImage,
                                          windowWidth, windowHeight,
                                          cropperShape, crooperSize);
        imageCropperDo->exec();
        return outputImage;
    }
};



#endif // IMAGECROPPERDIALOG_H
