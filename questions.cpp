#include "questions.h"

const int F_QUESTION_COUNT = 20;
const int B_QUESTION_COUNT = 30;

void initialize_questions(int chain, std::vector<std::string> &vector){
    if(chain == FORWARD){
        // TODO:
        // Implement the rest of the questions and responses for forward chaining
    }
    else if(chain == BACKWARD){
        vector[0] = "Does the patient have of show symptoms of a mental disorder?";
        vector[1] = "Patient does not meet criteria.";
        vector[2] = "Patient possibly qualifies for a mental disorder.";
        vector[3] = "Does the patient have suicial ideation?";
        vector[4] = "Does the patient have a feeling of sadness?";
        vector[5] = "Does the patient have impaired speech?";
        vector[6] = "Does the patient have blurred sense of identity?";
        vector[7] = "Does the patient have periods of manic moods?";
        vector[8] = "Does the patient have inability to relax?";
        vector[9] = "Has the patient expereinced hallucinations?";
        vector[10] = "Does the patient have memory loss(amnesia)?";
        vector[11] = "Does the patient have sleep trouble?";
        vector[12] = "Has the patient experienced a manic episode?";
        vector[13] = "Does the patient show physical signs of distress? ";
        vector[14] = "Does the patient have delusions?";
        vector[15] = "Does the patient have perception of people & things around them as distorted/unreal?";
        vector[16] = "Does the patient have trouble concentrating?";
        vector[17] = "Diagnose Patient with Bipolar l Disorder";
        vector[18] = "Does the patient have fear of losing control in public?";
        vector[19] = "Does the patient have manic mood?";
        vector[20] = "Dianose Patient with Dissociative Identity Disorder(DID - used to be known as Multiple Personality Disorder)";
        vector[21] = "How long has the patient have symptoms?";
        vector[22] = "Diagnose Diagnose Generalized Anxiety Disorder";
        vector[23] = "Diagnose Patient with  Panic Disorder with Agoraphobia";
        vector[24] = "How long has the patient expereinced distirbances?";
        // TODO:
        // Implement the rest of the questions and responses for backward chaining
    }
    else{
        std::cerr << "Invalid chain value" << std::endl;
    }
}

