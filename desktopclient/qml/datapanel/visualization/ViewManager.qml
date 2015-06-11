import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import "./propertyeditors" as DisplayOptions
import UIContextModel 1.0
import LayerManager 1.0
import "../../controls" as Controls
import "../../Global.js" as Global
import "../.." as Base


Item {
    id : viewmanager

    property var renderer

    Layout.minimumHeight: 22

    function addDataSource(filter, sourceName, sourceType){
        if ( filter.indexOf("=") !== -1){
            filter = "\"" + filter + "\""
        }
        var tab = layersmeta.getTab(2)

        if ( tab && tab.item && tab.item.coverage){
            tab.item.coverage.addCommand("adddrawer(" + tab.item.coverage.viewerId + ","+ sourceName + "," + filter + "," + sourceType + ")")
            if (!tab.item.manager.hasSelectionDrawer){
                tab.item.coverage.addCommand("adddrawer(" + tab.item.coverage.viewerId + ",selectiondrawer)")
                tab.item.manager.hasSelectionDrawer = true
            }
            tab.item.coverage.update()
        }
    }

    function entireMap() {
        var tab = layersmeta.getTab(2)
        if ( tab){
            tab.item.entireMap()
        }
    }


    Component {
        id : displayOptions
        DisplayOptions.LayerPropertyManagement{}
    }

    Component {
        id : layersinfo

        LayersInfo{

        }
    }

    Component{
        id : metadata
        MetaData{}
    }

    Rectangle {
        id : header
        width : parent.width
        height : 24
        anchors.top : parent.top
        color : Global.alternatecolor3
        TextField{
            id : nativeCoords
            width : 155;
            height : 18
            anchors.right: parent.right
            anchors.rightMargin: 4
            readOnly: true
            anchors.verticalCenter: parent.verticalCenter
            text : renderer.currentLatLon
        }

        TextField{
            id : otherCoords
            width : nativeCoords.width - 14;
            height : 18
            anchors.right: nativeCoords.left
            anchors.rightMargin: 4
            readOnly: true
            anchors.verticalCenter: parent.verticalCenter
            text : renderer.currentCoordinate
        }
    }

    TabView{
        id : layersmeta
        anchors.fill: parent

        Component.onCompleted: {
            var tab =addTab(qsTr("Display Options"), displayOptions)
            tab.active = true
            tab.item.renderer = renderer

            addTab(qsTr("Layers Info"), layersinfo)
            tab = addTab(qsTr("Metadata"), metadata)
            tab.active = true // we need to be active as layers maybe added to it
        }

        style: Base.TabStyle1{
        }
    }



}

