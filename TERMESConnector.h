/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class TERMESConnector */

#ifndef _Included_TERMESConnector
#define _Included_TERMESConnector
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     TERMESConnector
 * Method:    getKeypoints
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_TERMESConnector_getKeypoints
  (JNIEnv *, jclass);

/*
 * Class:     TERMESConnector
 * Method:    getNextFrame
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getNextFrame
  (JNIEnv *, jclass);

/*
 * Class:     TERMESConnector
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_TERMESConnector_start
  (JNIEnv *, jclass);

/*
 * Class:     TERMESConnector
 * Method:    releaseCamera
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_TERMESConnector_releaseCamera
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif