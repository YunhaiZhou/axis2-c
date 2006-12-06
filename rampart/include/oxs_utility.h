/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OXS_UTILITY_H
#define OXS_UTILITY_H


/**
  * @file oxs_utilty.h
  * @brief 
  */

#include <axis2_defines.h>
#include <axis2_env.h>

#ifdef __cplusplus
extern "C"
{
#endif
/* Generates an id for an element.
 * Specially used in xml encryption and signature references.
 * */
AXIS2_EXTERN axis2_char_t* AXIS2_CALL
oxs_util_generate_id(const axis2_env_t *env,
        axis2_char_t *prefix);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_UTILITY_H */
