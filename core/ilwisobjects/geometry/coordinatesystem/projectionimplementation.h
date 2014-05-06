#ifndef ProjectionImplementationIMPLEMENTATION_H
#define ProjectionImplementationIMPLEMENTATION_H

#include "Kernel_global.h"

namespace Ilwis {

class ConventionalCoordinateSystem;

struct ProjectionParameter {
    ProjectionParameter(){}
    ProjectionParameter(const QVariant& var, bool isSet=false) : _value(var), _isSet(isSet){}
    QVariant _value;
    bool _isSet=false;
};

class KERNELSHARED_EXPORT ProjectionImplementation
{
public:

    ProjectionImplementation(const QString& type=sUNDEF);

    virtual ~ProjectionImplementation() {}

    virtual Coordinate latlon2coord(const LatLon&) const = 0;
    virtual LatLon coord2latlon(const Coordinate&) const = 0;
    virtual bool prepare(const QString& parms="")=0;
    virtual QString type() const;
    virtual void setCoordinateSystem(ConventionalCoordinateSystem *csy);

    QVariant parameter(Projection::ProjectionParamValue type) const;
    virtual void setParameter(Projection::ProjectionParamValue type, const QVariant& value);
    QString parameterName(Projection::ProjectionParamValue pv) const;
    virtual QString toProj4() const = 0;


    bool isEqual(const QScopedPointer<ProjectionImplementation> &projimpl);
    QString toWKT(bool pretty=false);
protected:
    ConventionalCoordinateSystem *_coordinateSystem;

private:
    QHash<Projection::ProjectionParamValue, ProjectionParameter> _parameters;
    QString _projtype;
};
}


#endif // ProjectionImplementationIMPLEMENTATION_H
