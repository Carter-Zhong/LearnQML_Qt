import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Qt 开启一个线程")

    Text
    {
        id: numsText
        height: 40
        width: 1000
        anchors.centerIn: parent
        font.bold: true
        color: "lightBlue"
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: O_Thread.data
    }

    Row
    {
        anchors.horizontalCenter: numsText.horizontalCenter
        anchors.top: numsText.bottom
        anchors.topMargin: 50
        spacing: 30

        Button
        {
            width: 140
            height: 45
            text: qsTr("开始")
            onClicked:
            {
                O_Thread.start();
                console.log("开启一个线程")
            }
        }

        Button
        {
            width: 140
            height: 45
            text: qsTr("停止")
            onClicked:
            {
                O_Thread.stop()
                console.log("将线程停止")
            }
        }
    }


}
