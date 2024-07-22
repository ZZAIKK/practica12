#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QLibraryInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Conectar el QComboBox al slot para cambiar el idioma
    connect(ui->cmbldioma, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Widget::cambiarIdioma);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::cambiarIdioma(int index)
{
    QString rutaQM;

    if (index == 1) {
        // Cargar archivo de traducción al inglés
        rutaQM = "C:/Users/REDMI/Documents/practica12/traenglish.qm";
    } else {
        // Cargar archivo de traducción al español
        rutaQM = "C:/Users/REDMI/Documents/practica12/traspanish.qm";
    }

    if (traductor.load(rutaQM)) {
        qApp->installTranslator(&traductor);
    } else {
        qApp->removeTranslator(&traductor);
    }

    retranslateUi();
}

void Widget::retranslateUi()
{
    ui->retranslateUi(this);
}
