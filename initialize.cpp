#include "initialize.h"

// starting index is 1
const int CONCL_LIST_SIZE = 13 + 1;
const int VAR_LIST_SIZE = 31 + 1;

void init_concl_list(std::vector<std::string> &vector) {
    vector[1] = "DISORDER";
    vector[2] = "QUALIFY";
    vector[3] = "DISORDER";
    vector[4] = "DISORDER";
    vector[5] = "DISORDER";
    vector[6] = "DISORDER";
    vector[7] = "DISORDER";
    vector[8] = "DISORDER";
    vector[9] = "DISORDER";
    vector[10] = "DISORDER";
    vector[11] = "DISORDER";
    vector[12] = "DISORDER";
    vector[13] = "DISORDER";
}

// TODO:
// review for abbreviations of variable names
void init_var_list(std::vector<std::string> &vector) {
    vector[1] = "SYMPTOMS";
    vector[2] = "QUALIFY";
    vector[3] = "SUICIDAL IDEATION";
    vector[4] = "SADNESS";
    vector[5] = "MENTAL HEALTH PROBLEMS";
    vector[6] = "SIGNIFICANT STRESS";
    vector[7] = "DETACHED";
    vector[8] = "DISTORTED UNREAL";
    vector[9] = "AMNESIA";
    vector[10] = "ABILITY TO COPE";
    vector[11] = "BLURRED IDENTITY";
    vector[12] = "MANIC MOODS";
    vector[13] = "FATIGUE";
    vector[14] = "LOW SELF-ESTEEM";
    vector[15] = "MANIC EPISODE";
    vector[16] = "HOPELESSNESS";
    vector[17] = "LOST PLEASURE";
    vector[18] = "DEPRESSIVE/HYPOMANIC AFTER MANIC EPISODE";
    vector[19] = "TALKATIVENESS";
    vector[20] = "INCREASED ENERGY";
    vector[21] = "RELAX INABILITY";
    vector[22] = "DECISION FEAR";
    vector[23] = "OVERPROPORTIONAL ANXIETY";
    vector[24] = "PUBLIC FEAR";
    vector[25] = "PHYSICAL DISTRESS";
    vector[26] = "IMPAIRED SPEECH";
    vector[27] = "DISORG MOTOR BEHAVIOR";
    vector[28] = "BIZARRE BEHAVIOR";
    vector[29] = "HALLUCINATIONS";
    vector[29] = "DISTURBANCES";
    vector[30] = "DIMINISHED EXPRESSIONS";
    vector[31] = "DELUSIONS";
}

// TODO:
// create initialization function for conclusion variable list