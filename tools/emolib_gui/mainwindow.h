#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QCamera>
#include <QElapsedTimer>
#include <QtCharts/QChartGlobal>
#include <QLabel>
#include <QAudioBuffer>
#include <QVideoWidget>

class WavFile;

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class XYSeriesIODevice;

QT_BEGIN_NAMESPACE
class QAudioInput;
class QAudioOutput;
class QAudioProbe;
class QVideoProbe;
QT_END_NAMESPACE

class QMediaRecorder;
class QAudioRecorder;
class QMediaPlayer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_m_cmbClassifier_currentIndexChanged(int index);

    void on_m_cmbInput_currentIndexChanged(int index);

    void on_m_btnPlay_clicked();

    void on_m_btnBrowse_clicked();

private:
    void setupCameraPage();
    void setupAudioPage();
    void setupImagePage();
    void setupVideoPage();

    void selectImagePage();
    void selectMicAudioPage();
    void selectFileAudioPage();
    void selectCameraPage();
    void selectVideoPage();
    void choosePage();
    void openImage();
    bool loadImage(const QString &);

    void openAudio();
    bool loadAudio(const QString &);

    void openVideo();
    bool loadVideo(const QString &);

public slots:
    void processFrame(QVideoFrame frame);
    void processBuffer(QAudioBuffer buffer);

private:
    Ui::MainWindow*   ui;
    QChartView*       m_chart_view;
    QChart*           m_chart;
    QChart*           m_audio_chart;
    QBarSet*          m_emotionSet;
    QAudioRecorder*   m_audioRecorder;
    QMediaPlayer*     m_mediaPlayer;
    QCamera*          m_camera;
    WavFile*          m_file;
    QImage            m_selectedImage;
    QPixmap           m_cachedPixmap;
    QStringList       m_categories;
    QStringList       m_classifierTypes;
    QStringList       m_inputTypes;
    QVideoProbe*      m_videoProbe;
    QAudioProbe*      m_audioProbe;
    QVideoWidget*     m_videoWidget;
    QBarCategoryAxis* m_axis;
    XYSeriesIODevice* m_device;
    QLineSeries*      m_series;
    QAudioInput*      m_audioInput;
    QAudioOutput*      m_audioOutput;
};

#endif // MAINWINDOW_H