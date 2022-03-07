#include "lsystem.h"

LSystem::LSystem()
    : axiom()
    , state()
    , sub_rules() { }

LSystem::LSystem(QString axiom)
    : axiom(axiom)
    , state(axiom)
    , sub_rules() { }

void LSystem::generate(qint32 num_gens) {
    for (qint32 i = 0; i < num_gens; i++) {
        QString new_state;
        for (const QChar& c : this->state) {
            if (sub_rules.find(c) != sub_rules.end()) {
                new_state += sub_rules[c];
            }
            else {
                new_state += c;
            }
        }
        this->state = new_state;
    }
}

void LSystem::add_rule(const QChar& from, const QString& to) {
    this->sub_rules.insert(from, to);
}

void LSystem::remove_rule(const QChar& from) {
    this->sub_rules.remove(from);
}

void LSystem::reset_state() {
    this->state = this->axiom;
}

void LSystem::set_state(const QString& s) {
    this->state = s;
}

QString LSystem::get_state() {
    return this->state;
}

void LSystem::set_rules(const QHash<QChar, QString>& rules) {
    this->sub_rules = rules;
}

QHash<QChar, QString> LSystem::get_rules() {
    return this->sub_rules;
}
