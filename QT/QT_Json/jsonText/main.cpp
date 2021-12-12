#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

void writeJson();

void readJson();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    writeJson();
    readJson();

    return a.exec();
}

void writeJson()
{
    QJsonObject obj;
    obj.insert("Name", "Ace");
    obj.insert("Sex", "man");
    obj.insert("Age", 20);

    QJsonObject subObj;
    subObj.insert("Father", "Gol.D.Doger");
    subObj.insert("Monther", "Portagas.D.Rouge");
    QJsonArray array;
    array.append("Sabo");
    array.append("Monkey D. Luffy");
    subObj.insert("Brother", array);
    obj.insert("Family", subObj);
    obj.insert("IsAlive", false);
    obj.insert("Comment", "yyds");

    QJsonDocument doc(obj);
    QByteArray json = doc.toJson();

    QFile file("d:\\ace.json");
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}

void readJson()
{
    QFile file("d:\\ace.json");
    file.open(QFile::ReadOnly);
    QByteArray json = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(json);
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QStringList keys = obj.keys();
        for(int i=0; i<keys.size(); ++i)
        {
            QString key = keys.at(i);
            QJsonValue value = obj.value(key);
            if(value.isBool())
            {
                qDebug() << key << ":" << value.toBool();
            }
            if(value.isString())
            {
                qDebug() << key << ":" << value.toString();
            }
            if(value.isDouble())
            {
                qDebug() << key << ":" << value.toInt();
            }
            if(value.isObject())
            {
                qDebug() << key << ":";
                qDebug()<< key << ":";
                // 直接处理内部键值对, 不再进行类型判断的演示
                QJsonObject subObj = value.toObject();
                QStringList ls = subObj.keys();
                for(int i=0; i<ls.size(); ++i)
                {
                    QJsonValue subVal = subObj.value(ls.at(i));
                    if(subVal.isString())
                    {
                        qDebug() << "   " << ls.at(i) << ":" << subVal.toString();
                    }
                    if(subVal.isArray())
                    {
                        QJsonArray array = subVal.toArray();
                        qDebug() << "   " << ls.at(i) << ":";
                        for(int j=0; j<array.size(); ++j)
                        {
                            // 因为知道数组内部全部为字符串, 不再对元素类型进行判断
                            qDebug() << "       " << array[j].toString();
                        }
                    }
                }
            }
        }
    }




}
