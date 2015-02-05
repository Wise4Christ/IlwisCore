#ifndef SELECTIONDRAWER_H
#define SELECTIONDRAWER_H

#include <QObject>
#include <QVariant>
#include "box.h"
#include "simpledrawer.h"

namespace Ilwis{

namespace Geodrawer{
class SelectionDrawer : public SimpleDrawer
{
public:
    SelectionDrawer(DrawerInterface* parentDrawer, RootDrawer *rootdrawer, const IOOptions &options);
    ~SelectionDrawer();

    bool draw(QOpenGLContext *openglContext, const IOOptions& options=IOOptions()) ;
    bool prepare(PreparationType prepType, const IOOptions& options,QOpenGLContext *openglContext=0);
    void unprepare(PreparationType prepType);
    bool isPrepared(quint32 type=ptALL) const;

    void setAttribute(const QString& attrName, const QVariant& attrib);
    bool drawerAttribute(const QString drawername, const QString& attrName, const QVariant& attrib);
    DrawerInterface::DrawerType drawerType() const;
    quint32 defaultOrder() const;

    const QMatrix4x4 &mvpMatrix() const;

    static DrawerInterface *create(DrawerInterface *parentDrawer, RootDrawer *rootdrawer, const IOOptions &options);

    NEW_DRAWER

private:
   std::vector<VertexPosition> _vertices;
   std::vector<VertexIndex> _indices;
   std::vector<VertexColor> _colors;
   QMatrix4x4 _view,_projection, _model, _mvp;
   QMatrix4x4 _oldMatrix;

};
}
}

#endif // SELECTIONDRAWER_H