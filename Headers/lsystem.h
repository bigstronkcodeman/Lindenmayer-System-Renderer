#ifndef LSYSTEM_H
#define LSYSTEM_H
#include <QHash>
#include <QObject>

class LSystem {
public:
    LSystem();
    LSystem(QString axiom);

    void generate(qint32 num_gens);
    void add_rule(const QChar& from, const QString& to);
    void remove_rule(const QChar& from);
    void reset_state();

    void set_state(const QString& s);
    QString get_state();
    void set_rules(const QHash<QChar, QString>& rules);
    QHash<QChar, QString> get_rules();
private:
    QString axiom;
    QString state;
    QHash<QChar, QString> sub_rules;
};
#endif // LSYSTEM_H
