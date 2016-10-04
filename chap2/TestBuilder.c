#include "TestBuilder.h"

static void initRelations(TestBuilder* const me);
static void cleanUpRelations(TestBuilder* const me);

void TestBuilder_Init(TestBuilder* const me) {
    initRelations(me);
}

void TestBuilder_Cleanup(TestBuilder* const me) {
    cleanUpRelations(me);
}

struct ECG_Module* TestBuilder_getItsECG_Module(const TestBuilder* const me) {
    return (struct ECG_Module*) & (me->itsECG_Module);
}

struct HistogramDisplay* TestBuilder_getItsHistogramDisplay(const TestBuilder* const me) {
    return (struct HistogramDisplay*) & (me->itsHistogramDisplay);
}

struct TMDQueue* TestBuilder_getItsTMDQueue(const TestBuilder* const me) {
    return (struct TMDQueue*) & (me->itsTMDQueue);
}

TestBuilder * TestBuilder_Create(void) {
    TestBuilder* me = (TestBuilder *) malloc(sizeof(TestBuilder));
    if (me != NULL) {
        TestBuilder_Init(me);
    }
    return me;
}

void TestBuilder_Destroy(TestBuilder* const me) {
    if (me != NULL){
        TestBuilder_Cleanup(me);
    }
    free(me);
}

static void initRelations(TestBuilder* const me) {
    ECG_Module_Init(&(me->itsECG_Module));
    HistogramDisplay_Init(&(me->itsHistogramDisplay));
    TMDQueue_Init(&(me->itsTMDQueue));
    ECG_Module_setItsTMDQueue(&(me->itsECG_Module),&(me->itsTMDQueue));
    HistogramDisplay_setItsTMDQueue(&(me->itsHistogramDisplay),&(me->itsTMDQueue));
}

static void cleanUpRelations(TestBuilder* const me) {
    TMDQueue_Cleanup(&(me->itsTMDQueue));
    HistogramDisplay_Cleanup(&(me->itsHistogramDisplay));
}
