#ifndef CREATERASTERCOVERAGE_H
#define CREATERASTERCOVERAGE_H


namespace Ilwis {
namespace BaseOperations {
class CreateRasterCoverage :  public OperationImplementation
{
public:
    CreateRasterCoverage();

    CreateRasterCoverage(quint64 metaid, const Ilwis::OperationExpression &expr);

    bool execute(ExecutionContext *ctx, SymbolTable& symTable);
    static Ilwis::OperationImplementation *create(quint64 metaid,const Ilwis::OperationExpression& expr);
    Ilwis::OperationImplementation::State prepare(ExecutionContext *ctx,const SymbolTable&);

    static quint64 createMetadata();

    NEW_OPERATION(CreateRasterCoverage);

private:
    IDomain _domain;
    IDomain _stackDomain;
    IGeoReference _grf;
    std::vector<QString> _stackValueStrings;
    std::vector<double> _stackValueNumbers;
    std::vector<IRasterCoverage> _bands;
    bool _autoresample;

    bool parseStackDefintion(const QString &stackDef);
    bool parseStackDefintionNumericCase(const QString &stackDef);
    bool parseStackDefintionTimeCase(const QString &stackDef);
};
}
}
#endif // CREATERASTERCOVERAGE_H