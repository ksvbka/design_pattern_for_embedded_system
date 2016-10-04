#ifndef TestBuilder_H
#define TestBuilder_H

#include <stdio.h>
#include "ECGPkg.h"
#include "ECG_Module.h"
#include "HistogramDisplay.h"
#include "TMDQueue.h"

/* class TestBuilder */
typedef struct TestBuilder TestBuilder;
struct TestBuilder {
    struct ECG_Module itsECG_Module;
    struct HistogramDisplay itsHistogramDisplay;
    struct TMDQueue itsTMDQueue;
};

/* Constructors and destructors:*/
void TestBuilder_Init(TestBuilder* const me);
void TestBuilder_Cleanup(TestBuilder* const me);

struct ECG_Module* TestBuilder_getItsECG_Module(const TestBuilder* const me);
struct HistogramDisplay* TestBuilder_getItsHistogramDisplay(const TestBuilder* const me);
struct TMDQueue* TestBuilder_getItsTMDQueue(const TestBuilder* const me);

TestBuilder * TestBuilder_Create(void);
void TestBuilder_Destroy(TestBuilder* const me);

#endif
