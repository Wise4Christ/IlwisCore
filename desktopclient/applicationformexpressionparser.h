#ifndef APPLICATIONFORMEXPRESSIONPARSER_H
#define APPLICATIONFORMEXPRESSIONPARSER_H

#include <QObject>
#include <QStringList>
#include "ilwistype.h"

namespace Ilwis {
class Resource;

}
class ApplicationFormExpressionParser : public QObject
{
    Q_OBJECT
public:
    enum FieldType{ ftTEXTEDIT=1, ftTEXTAREA=2, ftCOMBOBOX=4, ftCHECKBOX=8, ftRADIOBUTTON=16};
    ApplicationFormExpressionParser();

    Q_INVOKABLE QString index2Form(quint64 metaid) const;
    Q_INVOKABLE QString createWorkflowForm(quint64) const;
private:
    struct FormParameter {
        int _fieldType;
        QStringList _choiceList;
        QString _label;
        IlwisTypes _dataType;
        quint32 _isOptional;
        int _optionGroup;

    };



    FormParameter addParameter(const Ilwis::Resource &resource, quint32 index, const QStringList &choices, bool optional, int optionGroup) const;
    std::vector<FormParameter> getParameters(quint64 metaid) const;
    void setParameter(const Ilwis::Resource &resource, bool &inChoiceList, std::vector<FormParameter> &parameters, QString &part, QStringList &choices, int &parmCount, bool isOptional, int optionGroup) const;
    QString setInputIcons(const QString& iconField, const QString& iconField2, const std::vector<FormParameter>& parameters, int i, int& imagewidth) const;
    std::vector<ApplicationFormExpressionParser::FormParameter> getOutputParameters(quint64 metaid) const;
    QString makeFormPart(int width, const std::vector<FormParameter> &parameters, bool input, QString &results) const;
    QString iconName(IlwisTypes dataType) const;
    QString keys(IlwisTypes type) const;

    std::vector<FormParameter> createWorkflowMetadata(quint64 metaid) const;
    QString formats(const QString &query) const;
};

#endif // APPLICATIONFORMEXPRESSIONPARSER_H
