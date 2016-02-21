import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import "../Global.js" as Global

DropArea {
    property alias content : textid.text
    property string labelText
    property int labelWidth
    property bool textCanBeCopied : false
    property int fontSize : 8
    property bool readOnly : false;
    property bool transparentBackgrond : true
    property var regexvalidator
    property bool boldLabel : true
    property int editWidth : width - label.width
    height : Global.rowHeight

    Text {
        id : label
        height : parent.height
        width : labelWidth
        text : labelText
        font.weight: boldLabel ? Font.Bold : Font.DemiBold
        font.pointSize: fontSize
        y :3
    }
    TextField{
        id : textid
        anchors.left : label.right
        height : parent.height
        width : editWidth
        text : content
        font.pointSize: fontSize
        readOnly : parent.readOnly

        property string oldText

        style: TextFieldStyle {
            background: Rectangle {
                radius: 3
                width : parent.width
                height: parent.height
                border.color: parent.enabled ? Global.edgecolor : "transparent"
                border.width: textid.readOnly ? 0: 1
                color : transparentBackgrond ? "transparent" : "white"
            }
        }
        onTextChanged: {
            if ( regexvalidator){
                var regex = regexvalidator
                if (!regex.test(textid.text)){
                    textid.text = textid.oldText
                }
                oldText = textid.text
            }
        }
    }
    onDropped : {
        content = drag.source.message
        console.debug(drag.source.message)
    }
}

