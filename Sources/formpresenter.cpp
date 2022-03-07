#include "formpresenter.h"

FormPresenter::FormPresenter(View* v)
    : lsys(nullptr)
    , view(v) { }

FormPresenter::~FormPresenter() {
    delete lsys;
}

void FormPresenter::add_rule_button_clicked() {
    view->add_rule_entry();
}

void FormPresenter::generate_button_clicked() {
    if (lsys) {
        delete lsys;
    }

    QString axiom = view->get_axiom_string();
    QColor fill_color = view->get_fill_color();
    qreal initial_angle = view->get_initial_angle();
    qreal turn_angle = view->get_turn_angle();
    qreal turn_increment = view->get_turn_increment();
    qint32 iterations = view->get_iterations();
    qreal line_length = view->get_line_length();
    qreal scale_factor = view->get_scale_factor();
    qreal line_width = view->get_line_width();
    qreal width_increment = view->get_width_increment();
    Turtle* turtle = view->get_turtle();

    turtle->reset();
    TurtleState turtle_state;
    turtle_state.bearing = initial_angle;
    turtle_state.bearing_inc = turn_angle;
    turtle_state.turn_inc = turn_increment;
    turtle_state.line_width = line_width / 10.0;
    turtle_state.line_width_inc = width_increment;
    turtle_state.line_length = line_length;
    turtle_state.line_scale_factor = scale_factor;
    turtle->set_state(turtle_state);
    turtle->set_fill_color(fill_color);

    lsys = new LSystem(axiom);
    lsys->set_rules(view->get_sub_entries());
    lsys->generate(iterations);

    turtle->execute_instructions(lsys->get_state());
    view->center_graphics_output();
}

void FormPresenter::leaf_preset() {
    FormDataBundle data;
    data.axiom = "a";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 45;
    data.turn_increment = 0;
    data.iterations = 10;
    data.line_length = 8;
    data.scale_factor = 1.36;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', ">F<"},
        {'a', "F[+x]Fb"},
        {'b', "F[-y]Fa"},
        {'x', "a"},
        {'y', "b"}
    };
    view->fill_form(data);
}

void FormPresenter::thistle_preset() {
    FormDataBundle data;
    data.axiom = "Y";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 25.7;
    data.turn_increment = 0;
    data.iterations = 5;
    data.line_length = 15;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'X', "X[-FFF][+FFF]FX"},
        {'Y', "YFX[+Y][-Y]"}
    };
    view->fill_form(data);
}

void FormPresenter::coral_preset() {
    FormDataBundle data;
    data.axiom = "F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 22.5;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 15;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF+[+F-F-F]-[-F+F+F]"}
    };
    view->fill_form(data);
}

void FormPresenter::bush_preset() {
    FormDataBundle data;
    data.axiom = "F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 35;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 10;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F[+FF][-FF]F[-F][+F]F"}
    };
    view->fill_form(data);
}

void FormPresenter::spruce_preset() {
    FormDataBundle data;
    data.axiom = "VZFFF";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 20;
    data.turn_increment = 0;
    data.iterations = 9;
    data.line_length = 20;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'V', "[+++W][---W]YV"},
        {'W', "+X[-W]Z"},
        {'X', "-W[+X]Z"},
        {'Y', "YZ"},
        {'Z', "[-FFF][+FFF]F"}
    };
    view->fill_form(data);
}

void FormPresenter::binary_tree_preset() {
    FormDataBundle data;
    data.axiom = "FX";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 40;
    data.turn_increment = 0;
    data.iterations = 10;
    data.line_length = 375;
    data.scale_factor = 1.75;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'X', "<[-FX]+FX"}
    };
    view->fill_form(data);
}

void FormPresenter::foxtail_preset() {
    FormDataBundle data;
    data.axiom = "X";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 20;
    data.turn_increment = 0;
    data.iterations = 7;
    data.line_length = 3.5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF"},
        {'X', "F[+X]F[-X]+X"}
    };
    view->fill_form(data);
}

void FormPresenter::sprig_preset() {
    FormDataBundle data;
    data.axiom = "aF";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 12;
    data.turn_increment = 0;
    data.iterations = 16;
    data.line_length = 3.5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'a', "FFFFFv[+++h][---q]fb"},
        {'b', "FFFFFv[+++h][---q]fc"},
        {'c', "FFFFFv[+++fa]fd"},
        {'d', "FFFFFv[+++h][---q]fe"},
        {'e', "FFFFFv[+++h][---q]fg"},
        {'g', "FFFFFv[---fa]fa"},
        {'h', "ifFF"},
        {'i', "fFFF[--m]j"},
        {'j', "fFFF[--n]k"},
        {'k', "fFFF[--o]l"},
        {'l', "fFFF[--p]"},
        {'m', "fFn"},
        {'n', "fFo"},
        {'o', "fFp"},
        {'p', "fF"},
        {'q', "rfF"},
        {'r', "fFFF[++m]s"},
        {'s', "fFFF[++n]t"},
        {'t', "fFFF[++o]u"},
        {'u', "fFFF[++p]"},
        {'v', "Fv"}
    };
    view->fill_form(data);
}

void FormPresenter::algae_preset() {
    FormDataBundle data;
    data.axiom = "aF";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 25;
    data.turn_increment = 0;
    data.iterations = 20;
    data.line_length = 3.5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'a', "FFFFFy[++++n][----t]fb"},
        {'b', "+FFFFFy[++++n][----t]fc"},
        {'c', "FFFFFy[++++n][----t]fd"},
        {'d', "-FFFFFy[++++n][----t]fe"},
        {'e', "FFFFFy[++++n][----t]fg"},
        {'g', "FFFFFy[+++fa]fh"},
        {'h', "FFFFFy[++++n][----t]fi"},
        {'i', "+FFFFFy[++++n][----t]fj"},
        {'j', "FFFFFy[++++n][----t]fk"},
        {'k', "-FFFFFy[++++n][----t]fl"},
        {'l', "FFFFFy[++++n][----t]fm"},
        {'m', "FFFFFy[---fa]fa"},
        {'n', "ofFFF"},
        {'o', "fFFFp"},
        {'p', "fFFF[-s]q"},
        {'q', "fFFF[-s]r"},
        {'r', "fFFF[-s]"},
        {'s', "fFfF"},
        {'t', "ufFFF"},
        {'u', "fFFFv"},
        {'v', "fFFF[+s]w"},
        {'w', "fFFF[+s]x"},
        {'x', "fFFF[+s]"},
        {'y', "Fy"}
    };
    view->fill_form(data);
}

void FormPresenter::birch_preset() {
    FormDataBundle data;
    data.axiom = "F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 22.5;
    data.turn_increment = 0;
    data.iterations = 6;
    data.line_length = 7;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF-[XY]+[XY]"},
        {'X', "+FY"},
        {'Y', "-FX"}
    };
    view->fill_form(data);
}

void FormPresenter::rings_preset() {
    FormDataBundle data;
    data.axiom = "F+F+F+F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 5.5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF+F+F+F+F+F-F"}
    };
    view->fill_form(data);
}

void FormPresenter::cross_preset() {
    FormDataBundle data;
    data.axiom = "F+F+F+F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 5;
    data.line_length = 5.5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F+FF++F+F"}
    };
    view->fill_form(data);
}

void FormPresenter::koch_snowflake_preset() {
    FormDataBundle data;
    data.axiom = "F++F++F";
    data.fill_color = Qt::red;
    data.initial_angle = 90;
    data.turn_angle = 60;
    data.turn_increment = 0;
    data.iterations = 5;
    data.line_length = 3;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F-F++F-F"}
    };
    view->fill_form(data);
}

void FormPresenter::sierpinski_arrowhead_preset() {
    FormDataBundle data;
    data.axiom = "YF";
    data.fill_color = Qt::red;
    data.initial_angle = 60;
    data.turn_angle = 60;
    data.turn_increment = 0;
    data.iterations = 8;
    data.line_length = 3;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'X', "YF+XF+Y"},
        {'Y', "XF-YF-X"}
    };
    view->fill_form(data);
}

void FormPresenter::hilbert_curve_preset() {
    FormDataBundle data;
    data.axiom = "X";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 7;
    data.line_length = 6;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'X', "-YF+XFX+FY-"},
        {'Y', "+XF-YFY-FX+"}
    };
    view->fill_form(data);
}

void FormPresenter::board_preset() {
    FormDataBundle data;
    data.axiom = "F+F+F+F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 10;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF+F+F+F+FF"}
    };
    view->fill_form(data);
}

void FormPresenter::crystal_preset() {
    FormDataBundle data;
    data.axiom = "F+F+F+F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 10;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "FF+F++F+F"}
    };
    view->fill_form(data);
}

void FormPresenter::quadratic_snowflake_preset() {
    FormDataBundle data;
    data.axiom = "F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 4;
    data.line_length = 10;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F-F+F+F-F"}
    };
    view->fill_form(data);
}

void FormPresenter:: quadratic_koch_island_preset() {
    FormDataBundle data;
    data.axiom = "F+F+F+F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 90;
    data.turn_increment = 0;
    data.iterations = 3;
    data.line_length = 5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F+F-F-FFF+F+F-F"}
    };
    view->fill_form(data);
}

void FormPresenter::pentaplexity_preset() {
    FormDataBundle data;
    data.axiom = "F++F++F++F++F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 36;
    data.turn_increment = 0;
    data.iterations = 3;
    data.line_length = 5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "F++F++F|F-F++F"}
    };
    view->fill_form(data);
}

void FormPresenter::levy_curve_preset() {
    FormDataBundle data;
    data.axiom = "F";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 45;
    data.turn_increment = 0;
    data.iterations = 8;
    data.line_length = 5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'F', "-F++F-"}
    };
    view->fill_form(data);
}

void FormPresenter::krishna_anklet_preset() {
    FormDataBundle data;
    data.axiom = "-X--X";
    data.fill_color = Qt::red;
    data.initial_angle = 0;
    data.turn_angle = 45;
    data.turn_increment = 0;
    data.iterations = 5;
    data.line_length = 5;
    data.scale_factor = 1;
    data.line_width = 1;
    data.width_increment = 0;
    data.rules = {
        {'X', "XFX--XFX"}
    };
    view->fill_form(data);
}
