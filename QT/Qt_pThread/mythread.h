#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
    Q_PROPERTY(int data READ getData WRITE setData NOTIFY dataChanged)

public:
    explicit MyThread() = default;
    ~MyThread() = default;

    // 重写run函数(线程执行的操作)
    void run()
    {
        isRuning = false;
        for(int i=1; i<=10000; ++i)
        {
            if(isRuning)
                break;
            setData(i);
            // 防止线程卡死
            usleep(1);
        }
    }

    Q_INVOKABLE int getData() const { return data_; }

    // 停止线程
    Q_INVOKABLE void stop()
    {
        isRuning = true;
        wait();
        // 停止并把将值恢复原始状态
        setData(0);
    }

signals:
    void dataChanged( const int data );

public:
    void setData( uint32_t data )
    {
        if(data != data_)
        {
            data_ = data;
            emit dataChanged(data_);
        }
    }

private:

    // 线程正在执行标志(用于停止线程使用)
    bool isRuning = false;

    uint32_t data_ = 0;
};

#endif // MYTHREAD_H
