#include "kernel.h"
#include "ilwisdata.h"
#include "symboltable.h"
#include "geos/geom/Coordinate.h"
#include "location.h"
#include "ilwiscoordinate.h"
#include "box.h"
#include "operationExpression.h"
#include "commandhandler.h"
#include "operationmetadata.h"
#include "operation.h"
#include "mastercatalog.h"
#include "operationhelper.h"
#include "workflownode.h"
#include "rangenode.h"
#include "workflow.h"

using namespace Ilwis;

bool Ilwis::operator==(const Ilwis::SPWorkFlowNode& node1, const Ilwis::SPWorkFlowNode& node2 ){
    if ( !node1)
        return false;
    if (!node2)
        return false;
    return node1->id() == node2->id();
}

bool Ilwis::operator<(const Ilwis::SPWorkFlowNode& node1, const Ilwis::SPWorkFlowNode& node2 ){
    if ( !node1)
        return false;
    if (!node2)
        return false;

    return node1->id() < node2->id();
}

bool Ilwis::operator==(const Ilwis::IdTypePair& node1, const Ilwis::IdTypePair& node2 ){

    return node1._nodeid == node2._nodeid && node1._nodeType == node2._nodeType;
}

WorkFlowNode::WorkFlowNode(const QString& name, const QString& description, quint64 id) : Identity(name, id, QString::number(id), description)
{

}

int WorkFlowNode::inputCount() const
{
    return _inputParameters1.size();
}

WorkFlowParameter &WorkFlowNode::inputRef(int index)
{
    if ( index < _inputParameters1.size())
        return _inputParameters1[index];
    throw ErrorObject(TR("Parameter index out of range"));
}

WorkFlowParameter WorkFlowNode::input(int index) const
{
    if ( index < _inputParameters1.size())
        return _inputParameters1[index];
    throw ErrorObject(TR("Parameter index out of range"));
}

void WorkFlowNode::addInput(const WorkFlowParameter &param, int index)
{
    if ( index == iUNDEF)    {
        _inputParameters1.push_back(param);
    }else{
        if ( index >= _inputParameters1.size())
            _inputParameters1.resize(index+1);
        _inputParameters1[index] = param;
    }
}

void WorkFlowNode::setFlow(const SPWorkFlowNode &fromNode, qint32 inParmIndex, qint32 outParmIndex, int attachRctIndxFrom, int attachRctIndxTo)
{
    if ( fromNode->type() == WorkFlowNode::ntRANGEJUNCTION) {
        if (owner()->id() == fromNode->owner()->id() ){
            inputRef(inParmIndex).inputLink(fromNode,RangeNode::rpOUTPUT);
            inputRef(inParmIndex).attachement(attachRctIndxFrom, true);
            inputRef(inParmIndex).attachement(attachRctIndxTo, false);
        }
        else if ( !owner() || (owner()->id() != fromNode->owner()->id()) ){
            inputRef(inParmIndex).inputLink(fromNode,RangeNode::rpFINALOUTPUT);
            inputRef(inParmIndex).attachement(attachRctIndxFrom, true);
            inputRef(inParmIndex).attachement(attachRctIndxTo, false);
        }
    }else {
        inputRef(inParmIndex).inputLink(fromNode,outParmIndex);
        inputRef(inParmIndex).attachement(attachRctIndxFrom, true);
        inputRef(inParmIndex).attachement(attachRctIndxTo, false);
    }
}

void WorkFlowNode::removedInput(int index)
{
    if ( index < _inputParameters1.size())    {
        _inputParameters1.erase(_inputParameters1.begin() + index);
    }
}

void WorkFlowNode::nodeId(quint64 id)
{
    Identity::setId(id);
    for(WorkFlowParameter& param : _inputParameters1){
        param.nodeId(id);
    }
}


void WorkFlowNode::box(const BoundingBox &box)
{
    _box = box;
}

BoundingBox WorkFlowNode::box() const
{
    return _box;
}

bool WorkFlowNode::collapsed() const
{
    return _collapsed;
}

void WorkFlowNode::collapsed(bool yesno)
{
    _collapsed = yesno;
}

std::shared_ptr<WorkFlowNode> WorkFlowNode::owner() const
{
    return _owner;
}

void WorkFlowNode::owner(std::shared_ptr<WorkFlowNode> own)
{
    _owner = own;
}

QString WorkFlowNode::label() const
{
    return _label;
}

void WorkFlowNode::label(const QString &lbl)
{
    _label = lbl;
}

NodeId WorkFlowNode::conditionIdOfTest() const
{
    return _conditionIdOfTest;
}

void WorkFlowNode::conditionIdOfTest(NodeId id)
{
    _conditionIdOfTest = id;
}

IOperationMetaData WorkFlowNode::operation() const
{
    return IOperationMetaData();
}

bool WorkFlowNode::isWorkflow() const
{
    return false;
}

void WorkFlowNode::removeSubNode(NodeId id)
{
}

bool WorkFlowNode::checkLinkDefintion(const QString &linkDef, NodeId& nid, int& outParameterIndex) const
{
    QStringList parts = linkDef.split("=");
    if ( parts.size() != 2){
          return false;
    }
    parts = parts[1].split(":");
    if ( parts.size() != 2){
       return false;
    }
    bool ok;
    nid = parts[0].toInt(&ok)        ;
    if ( !ok){
        return false;
    }
    outParameterIndex  = parts[1].toInt(&ok) ;
    if ( !ok){
       return false;
    }
    return true;
}

std::vector<SPWorkFlowNode> WorkFlowNode::subnodes(const QString &reason) const
{
    return std::vector<SPWorkFlowNode>();
}

void WorkFlowNode::addSubNode(const SPWorkFlowNode &node, const QString &reason)
{

}





