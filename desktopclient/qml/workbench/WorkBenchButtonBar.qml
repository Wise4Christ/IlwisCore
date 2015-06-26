import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.0
import MasterCatalogModel 1.0
import TranquilizerHandler 1.0
import UIContextModel 1.0
import "../Global.js" as Global

Rectangle {
    id : buttonB
    y : 0
    height : parent.height
    width : 80
    color : Global.alternatecolor1
    border.width : 1
    Layout.maximumWidth : 140

    //signal transitionInfoPane(string pagename)

    Action {
        id : navClicked
        onTriggered : {
            transitionInfoPane("Navigator.qml")
        }

    }

    Action {
        id : operClicked
        onTriggered : {
            transitionInfoPane("OperationSelection.qml")
        }

    }
    Action {
        id : propertiesClicked
        onTriggered : {
            transitionInfoPane("ObjectProperties.qml")
        }
    }
    Action {
        id : messagesClicked
        onTriggered : {
            transitionInfoPane("MessagesPane.qml")
        }
    }
    Action {
        id : progressClicked
        onTriggered : {
            transitionInfoPane("Tranquilizers.qml")
        }

    }
    Action {
        id : modellerClicked
        onTriggered : {
            transitionInfoPane("modeller/ModellerSelection.qml")
        }

    }
    Action {
        id : workflowsClicked
        onTriggered : {
            transitionInfoPane("workflow/WorkflowSelection.qml")
        }

    }
    Action {
        id : workspaceClicked
        onTriggered : {
            transitionInfoPane("Workspaces.qml")
        }

    }

    Action {
        id : prefClicked
        onTriggered : {
            mastercatalog.longAction()
        }

    }

    Action {
        id :maxButtons
        onTriggered: {
            buttonB.width = 55
        }
    }

    Action {
        id :minButtons
        onTriggered: {
            buttonB.width = 0
        }
    }

    Column {
        anchors.fill: parent
        Rectangle {
            height : 21
            width : buttonB.width
            color : Global.alternatecolor1
            Row {
                anchors.fill: parent
                Button{
                    id : full
                    height : 20
                    width :20
                    action : maxButtons
                    Image { anchors.centerIn : parent; source: "../images/max1.png" }
                }
                Button{
                    id : close
                    height : 20
                    width :20
                    action : minButtons
                    Image { anchors.centerIn : parent; source: "../images/min1.png" }
                }
            }
        }

        WorkBenchButton{
            id : nav
            objectName : "workbench_navbutton_mainui"
            action: navClicked
            iconname: "navigatorCS1.png"
            label: qsTr("Navigator")
        }

        WorkBenchButton{
            id : oper
            action: workspaceClicked
            iconname : "workspaceCS1.png"
            label: qsTr("Workspace")
        }
        WorkBenchButton{
            id : workspace
            action: operClicked
            iconname : "operationCS1.png"
            label: qsTr("Operations")
        }
        WorkBenchButton{
            id : modeller
            action: modellerClicked
            iconname : "modellerCS1.png"
            label: qsTr("Modeller")
        }
        WorkBenchButton{
            id : workflow
            action: workflowsClicked
            iconname : "modellerCS1.png"
            label: qsTr("Workflows")
        }
        WorkBenchButton{
            id : prop
            action : propertiesClicked
            iconname : "propertiesCS1.png"
            label: qsTr("Metadata")

        }
        WorkBenchButton{
            id : errors
            action : messagesClicked
            iconname : messagehandler.messageIcon
            label: qsTr("Messages")
        }
        WorkBenchButton{
            id : progress
            ProgressBar {
                anchors.top: progress.top
                anchors.topMargin: 5
                width : parent.width - 10
                x : 5
                height : 12
                maximumValue: 100
                minimumValue: 0
                value : tranquilizerHandler.aggregateValue
                opacity: value > 0 ? 0.35 : 0

            }

            action : progressClicked
            iconname : "progressCS1.png"
            label: qsTr("Progress")

        }
        WorkBenchButton{
            id : preferences
            action : prefClicked
            iconname : "preferencesCS1.png"
            label: qsTr("Preferences")

        }
    }
}
