#include "initialize.h"
#include <fstream>
#include <iostream>

// starting index is 1, so we add 1 to size
const int CONCL_LIST_SIZE = 13 + 1;
const int VAR_LIST_SIZE = 31 + 1;

// we have a maximum of 9 variables in our if clauses
// since we have 17 rules, with at most 9 variables each,
// the max length of our clause variable list is 153
const int CLAUSE_VAR_LIST_SIZE = 153 + 1;

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
void init_var_list(std::vector<Variable> &vector) {
    vector[1].set_name("SYMPTOMS");
    vector[2].set_name("QUALIFY");
    vector[3].set_name("SUICIDAL IDEATION");
    vector[4].set_name("SADNESS");
    vector[5].set_name("MENTAL HEALTH PROBLEMS");
    vector[6].set_name("SIGNIFICANT STRESS");
    vector[7].set_name("DETACHED");
    vector[8].set_name("DISTORTED UNREAL");
    vector[9].set_name("AMNESIA");
    vector[10].set_name("ABILITY TO COPE");
    vector[11].set_name("BLURRED IDENTITY");
    vector[12].set_name("MANIC MOODS");
    vector[13].set_name("FATIGUE");
    vector[14].set_name("LOW SELF-ESTEEM");
    vector[15].set_name("MANIC EPISODE");
    vector[16].set_name("HOPELESSNESS");
    vector[17].set_name("LOST PLEASURE");
    vector[18].set_name("DEPRESSIVE/HYPOMANIC AFTER MANIC EPISODE");
    vector[19].set_name("TALKATIVENESS");
    vector[20].set_name("INCREASED ENERGY");
    vector[21].set_name("RELAX INABILITY");
    vector[22].set_name("DECISION FEAR");
    vector[23].set_name("OVERPROPORTIONAL ANXIETY");
    vector[24].set_name("PUBLIC FEAR");
    vector[25].set_name("PHYSICAL DISTRESS");
    vector[26].set_name("IMPAIRED SPEECH");
    vector[27].set_name("DISORG MOTOR BEHAVIOR");
    vector[28].set_name("BIZARRE BEHAVIOR");
    vector[29].set_name("HALLUCINATIONS");
    vector[29].set_name("DISTURBANCES");
    vector[30].set_name("DIMINISHED EXPRESSIONS");
    vector[31].set_name("DELUSIONS");
}

// TODO:
// create initialization function for conclusion variable list
// need to specify types
void init_concl_var_list(std::vector<Variable> &vector){
    std::ifstream inputFile;
    std::string line;

    inputFile.open("./data/backward-chaining-clauselist.txt");
    for(int i = 1; i < CLAUSE_VAR_LIST_SIZE; i++){
        getline(inputFile, line);
        vector[i].set_name(line);
    }
}