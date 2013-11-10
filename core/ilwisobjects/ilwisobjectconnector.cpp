#include <QUrl>
#include "kernel.h"
#include "mastercatalog.h"
#include "connectorinterface.h"
#include "containerconnector.h"
#include "factory.h"
#include "abstractfactory.h"
#include "connectorfactory.h"
#include "ilwisobjectconnector.h"

using namespace Ilwis;

IlwisObjectConnector::IlwisObjectConnector(const Ilwis::Resource &resource, bool) : _resource(resource)
{
    const ConnectorFactory *factory = kernel()->factory<ConnectorFactory>("ConnectorFactory",resource);

    if ( factory)
         _incontainerconnector.reset(dynamic_cast<ContainerConnector *>(factory->createSuitable(Resource(resource.url(), itCONTAINER))));
    else {
        kernel()->issues()->log(TR("Cann't find suitable factory for %1 ").arg(resource.name()));
    }
}

IlwisTypes IlwisObjectConnector::type() const
{
    return _resource.ilwisType();
}

Resource &IlwisObjectConnector::source()
{
    return _resource;
}

std::unique_ptr<ContainerConnector> &IlwisObjectConnector::containerConnector(IlwisObject::ConnectorMode mode)
{
    if ( mode & IlwisObject::cmINPUT)
        return _incontainerconnector;
    else if ( mode & IlwisObject::cmOUTPUT)
        if ( _outcontainerconnector)
            return _outcontainerconnector;
    return _incontainerconnector;
}

const std::unique_ptr<ContainerConnector> &IlwisObjectConnector::containerConnector(IlwisObject::ConnectorMode mode) const
{
    if ( mode &IlwisObject:: cmINPUT)
        return _incontainerconnector;
    else if ( mode & IlwisObject::cmOUTPUT)
        if ( _outcontainerconnector)
            return _outcontainerconnector;
    return _incontainerconnector;
}
