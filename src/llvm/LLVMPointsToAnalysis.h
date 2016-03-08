#ifndef _LLVM_DG_POINTS_TO_ANALYSIS_H_
#define _LLVM_DG_POINTS_TO_ANALYSIS_H_

#include <llvm/IR/Function.h>
#include <llvm/IR/DataLayout.h>

#include "analysis/PSS.h"
#include "llvm/PSS.h"

namespace dg {

using analysis::pss::PSS;
using analysis::pss::PSSNode;
using analysis::pss::LLVMPSSBuilder;

template <typename PTType>
class LLVMPointsToAnalysis : public PTType
{
    LLVMPSSBuilder *builder;

public:
    LLVMPointsToAnalysis(const llvm::Module* M)
        :builder(new LLVMPSSBuilder(M)) {}

    // build new subgraphs on calls via pointer
    virtual bool functionPointerCall(PSSNode *where, PSSNode *what)
    {
    }

    void build()
    {
        this->setRoot(builder->buildLLVMPSS());
    }
};

}

#endif // _LLVM_DG_POINTS_TO_ANALYSIS_H_