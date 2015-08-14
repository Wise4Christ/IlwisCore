import QtQuick 2.2
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.0
import UIContextModel 1.0
import "../../controls" as Controls
import "../../Global.js" as Global
import ".." as DataPanel

Rectangle {
    id : modelmanager
    width: parent.width
    height: 62
    Component {
        id : modelLayerOptions
        LayerManagement{}
    }

    Component {
        id : operationForms
        OperationForms{}
    }

    Component{
        id : metadata
        MetaData{
        }
    }



    TabView{
        id : modellerProperties
        anchors.fill: parent
        tabPosition: Qt.BottomEdge
        onCurrentIndexChanged: {
            var tab= getTab(2)
        }

        function tabClicked(index){
            if ( currentIndex === index){
                if ( modelmanager.height <= 60){
                    canvas.state = "visible"
                }
                else{
                    canvas.state = ""
                    canvas.state = "invisible"
                }
            }

            currentIndex = index
        }


        Component.onCompleted: {
            var tab =addTab(qsTr("Model layers"), modelLayerOptions)
            tab.active = true

            addTab(qsTr("Operation Form"), operationForms)
            tab = addTab(qsTr("Metadata"), metadata)
            tab.active = true // we need to be active as layers maybe added to it
        }

        style: DataPanel.ButtonBarTabViewStyle{}
    }



}

