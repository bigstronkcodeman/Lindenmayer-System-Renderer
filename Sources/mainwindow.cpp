#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , form_presenter(this)
    , turtle() {
    ui->setupUi(this);

    QGraphicsView* graphics_view = get_graphics_view();
    graphics_view->setCacheMode(QGraphicsView::CacheBackground);
//    graphics_view->setRenderHints(QPainter::Antialiasing);
    new GraphicsViewZoom(graphics_view);
    turtle.set_graphics_view(graphics_view);

    add_rule_entry();
    initialize_color_combobox();

    connect(get_add_rule_btn(), SIGNAL(clicked()), &form_presenter, SLOT(add_rule_button_clicked()));
    connect(get_generate_btn(), SIGNAL(clicked()), &form_presenter, SLOT(generate_button_clicked()));
    connect(ui->leaf_button, SIGNAL(clicked()), &form_presenter, SLOT(leaf_preset()));
    connect(ui->thistle_button, SIGNAL(clicked()), &form_presenter, SLOT(thistle_preset()));
    connect(ui->coral_button, SIGNAL(clicked()), &form_presenter, SLOT(coral_preset()));
    connect(ui->bush_button, SIGNAL(clicked()), &form_presenter, SLOT(bush_preset()));
    connect(ui->spruce_button, SIGNAL(clicked()), &form_presenter, SLOT(spruce_preset()));
    connect(ui->binary_tree_button, SIGNAL(clicked()), &form_presenter, SLOT(binary_tree_preset()));
    connect(ui->foxtail_button, SIGNAL(clicked()), &form_presenter, SLOT(foxtail_preset()));
    connect(ui->sprig_button, SIGNAL(clicked()), &form_presenter, SLOT(sprig_preset()));
    connect(ui->algae_button, SIGNAL(clicked()), &form_presenter, SLOT(algae_preset()));
    connect(ui->birch_button, SIGNAL(clicked()), &form_presenter, SLOT(birch_preset()));
    connect(ui->rings_button, SIGNAL(clicked()), &form_presenter, SLOT(rings_preset()));
    connect(ui->cross_button, SIGNAL(clicked()), &form_presenter, SLOT(cross_preset()));
    connect(ui->koch_snowflake_button, SIGNAL(clicked()), &form_presenter, SLOT(koch_snowflake_preset()));
    connect(ui->sierpinski_arrowhead_button, SIGNAL(clicked()), &form_presenter, SLOT(sierpinski_arrowhead_preset()));
    connect(ui->hilbert_curve_button, SIGNAL(clicked()), &form_presenter, SLOT(hilbert_curve_preset()));
    connect(ui->board_button, SIGNAL(clicked()), &form_presenter, SLOT(board_preset()));
    connect(ui->crystal_button, SIGNAL(clicked()), &form_presenter, SLOT(crystal_preset()));
    connect(ui->quadratic_snowflake_button, SIGNAL(clicked()), &form_presenter, SLOT(quadratic_snowflake_preset()));
    connect(ui->quadratic_koch_island_button, SIGNAL(clicked()), &form_presenter, SLOT(quadratic_koch_island_preset()));
    connect(ui->pentaplexity_button, SIGNAL(clicked()), &form_presenter, SLOT(pentaplexity_preset()));
    connect(ui->levy_curve_button, SIGNAL(clicked()), &form_presenter, SLOT(levy_curve_preset()));
    connect(ui->krishna_anklet_button, SIGNAL(clicked()), &form_presenter, SLOT(krishna_anklet_preset()));
    connect(ui->center_output_button, SIGNAL(clicked()), this, SLOT(center_graphics_output()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initialize_color_combobox() {
    QComboBox* box = get_color_combobox();

    qint32 dim = 15;

    QPixmap red_pixmap(dim,dim);
    red_pixmap.fill(Qt::red);
    QIcon red_icon(red_pixmap);

    QPixmap green_pixmap(dim,dim);
    green_pixmap.fill(Qt::green);
    QIcon green_icon(green_pixmap);

    QPixmap blue_pixmap(dim,dim);
    blue_pixmap.fill(Qt::blue);
    QIcon blue_icon(blue_pixmap);

    box->addItem(red_icon, "red");
    box->addItem(green_icon, "green");
    box->addItem(blue_icon, "blue");
}

void MainWindow::clear_rule_form() {
    QFormLayout* form_layout = get_rule_form_layout();
    qint32 num_rules = form_layout->rowCount();
    for(qint32 i = 0; i < num_rules; i++) {
        form_layout->removeRow(0);
    }
}

void MainWindow::center_graphics_output() {
    QGraphicsView* graphics_view = get_graphics_view();
    QRectF bounding_rect = graphics_view->scene()->itemsBoundingRect();
    qreal marginx = bounding_rect.width() / 10.0;
    qreal marginy = bounding_rect.width() / 10.0;
    graphics_view->setSceneRect(graphics_view->scene()->itemsBoundingRect().adjusted(-marginx, -marginy, marginx, marginy));
    graphics_view->fitInView(graphics_view->sceneRect(), Qt::KeepAspectRatio);
}

QLineEdit* MainWindow::get_axiom_textbox() {
    return ui->axiom_textbox;
}

QComboBox* MainWindow::get_color_combobox() {
    return ui->fill_color_combobox;
}

QDoubleSpinBox* MainWindow::get_initial_angle_spinbox() {
    return ui->angle_spinbox;
}

QDoubleSpinBox* MainWindow::get_turn_angle_spinbox() {
    return ui->angle_increment_spinbox;
}

QDoubleSpinBox* MainWindow::get_turn_increment_spinbox() {
    return ui->turn_increment_spinbox;
}

QSpinBox* MainWindow::get_iterations_spinbox() {
    return ui->iterations_spinbox;
}

QDoubleSpinBox* MainWindow::get_line_length_spinbox() {
    return ui->line_length_spinbox;
}

QDoubleSpinBox* MainWindow::get_scale_factor_spinbox() {
    return ui->scale_factor_spinbox;
}

QDoubleSpinBox* MainWindow::get_line_width_spinbox() {
    return ui->line_width_spinbox;
}

QDoubleSpinBox* MainWindow::get_width_increment_spinbox() {
    return ui->width_increment_spinbox;
}

QPushButton* MainWindow::get_add_rule_btn() {
    return ui->add_rule_button;
}

QPushButton* MainWindow::get_generate_btn() {
    return ui->generate_button;
}

QFormLayout* MainWindow::get_rule_form_layout() {
    return ui->rule_form_layout;
}

QGraphicsView* MainWindow::get_graphics_view() {
    return ui->graphics_view;
}

QString MainWindow::get_axiom_string() {
    return get_axiom_textbox()->text();
}

QColor MainWindow::get_fill_color() {
    QComboBox* combobox = get_color_combobox();
    QString selection_str = combobox->currentData().toString();
    if (selection_str == "red") {
        return Qt::red;
    }
    else if (selection_str == "green") {
        return Qt::green;
    }
    else if (selection_str == "blue") {
        return Qt::blue;
    }
}

qreal MainWindow::get_initial_angle() {
    return get_initial_angle_spinbox()->value();
}

qreal MainWindow::get_turn_angle() {
    return get_turn_angle_spinbox()->value();
}

qreal MainWindow::get_turn_increment() {
    return get_turn_increment_spinbox()->value();
}

qint32 MainWindow::get_iterations() {
    return get_iterations_spinbox()->value();
}

qreal MainWindow::get_line_length() {
    return get_line_length_spinbox()->value();
}

qreal MainWindow::get_scale_factor() {
    return get_scale_factor_spinbox()->value();
}

qreal MainWindow::get_line_width() {
    return get_line_width_spinbox()->value();
}

qreal MainWindow::get_width_increment() {
    return get_width_increment_spinbox()->value();
}

QHash<QChar, QString> MainWindow::get_sub_entries() {
    QHash<QChar, QString> result;

    QFormLayout* rule_form_layout = get_rule_form_layout();
    for (qint32 i = 0; i < rule_form_layout->rowCount(); i++) {
        QLineEdit* from_textbox = static_cast<QLineEdit *>(rule_form_layout->itemAt(i, QFormLayout::LabelRole)->widget());
        QLineEdit* to_textbox = static_cast<QLineEdit *>(rule_form_layout->itemAt(i, QFormLayout::FieldRole)->widget());

        QString from_str = from_textbox->text();
        QString to_str = to_textbox->text();
        if (from_str.length() == 0) {
            if (rule_form_layout->rowCount() > 1) {
                rule_form_layout->removeRow(i);
            }
        }
        else {
            result.insert(from_str.at(0), to_str);
        }
    }

    return result;
}

void MainWindow::add_rule_entry(const QChar& c, const QString& s) {
    QLineEdit* rule_textbox = new QLineEdit();
    rule_textbox->setPlaceholderText("Enter a substitution rule...");
    rule_textbox->setText(s);

    QLineEdit* char_textbox = new QLineEdit();
    char_textbox->setAlignment(Qt::AlignCenter);
    char_textbox->setMaxLength(1);
    char_textbox->setMaximumWidth(20);
    char_textbox->setText("");

    get_rule_form_layout()->addRow(char_textbox, rule_textbox);
}

Turtle* MainWindow::get_turtle() {
    return &turtle;
}

void MainWindow::fill_form(const FormDataBundle& form_data) {
    clear_rule_form();
    get_axiom_textbox()->setText(form_data.axiom);

    QComboBox* combobox = get_color_combobox();
    QColor color = form_data.fill_color;
    if (color == Qt::red) {
        combobox->setCurrentIndex(combobox->findData("red"));
    }
    else if (color == Qt::green) {
        combobox->setCurrentIndex(combobox->findData("green"));
    }
    else if (color == Qt::blue) {
        combobox->setCurrentIndex(combobox->findData("blue"));
    }

    get_initial_angle_spinbox()->setValue(form_data.initial_angle);
    get_turn_angle_spinbox()->setValue(form_data.turn_angle);
    get_turn_increment_spinbox()->setValue(form_data.turn_increment);
    get_iterations_spinbox()->setValue(form_data.iterations);
    get_line_length_spinbox()->setValue(form_data.line_length);
    get_scale_factor_spinbox()->setValue(form_data.scale_factor);
    get_line_width_spinbox()->setValue(form_data.line_width);
    get_width_increment_spinbox()->setValue(form_data.width_increment);

    QHashIterator<QChar, QString> it(form_data.rules);
    while (it.hasNext()) {
        it.next();
        add_rule_entry(it.key(), it.value());
    }
}
