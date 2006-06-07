/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_H
#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_H

/**
 * @file axis2_woden_interface_fault_ref_element.h
 * @brief Axis2 Interface Fault Reference Element Interface
 * This interface represents a &lt;fault&gt; child element of the
 * WSDL &lt;interface&gt; element. 
 * It declares the behaviour required to support parsing, 
 * creating and manipulating a &lt;fault&gt; element.
 */

#include <axis2_allocator.h>
#include <axis2_env.h>
#include <axis2_error.h>
#include <axis2_string.h>
#include <axis2_utils.h>
#include <axis2_hash.h>
#include <axis2_qname.h>
#include <axis2_uri.h>
#include <axis2_array_list.h>
#include <woden/axis2_woden.h>
#include <woden/wsdl20/xml/axis2_woden_documentable_element.h>
#include <woden/wsdl20/xml/axis2_woden_configurable_element.h>
#include <woden/wsdl20/xml/axis2_woden_nested_element.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct axis2_woden_interface_fault_ref_element axis2_woden_interface_fault_ref_element_t;
typedef struct axis2_woden_interface_fault_ref_element_ops axis2_woden_interface_fault_ref_element_ops_t;
typedef union axis2_woden_interface_fault_ref_element_base axis2_woden_interface_fault_ref_element_base_t;

/** @defgroup axis2_woden_interface_fault_ref_element Interface Fault Reference Element
  * @ingroup axis2_interface
  * @{
  */

struct axis2_woden_interface_fault_ref_element_ops
{
   /** 
     * Deallocate memory
     * @return status code
     */
    axis2_status_t (AXIS2_CALL *
    free) (
            void *interface_fault_ref_element,
            const axis2_env_t *env);
 
    axis2_woden_obj_types_t (AXIS2_CALL *
    type) (
            void *interface_fault_ref_element,
            const axis2_env_t *env);

    axis2_status_t (AXIS2_CALL *
    set_ref) (
            void *iface_fault_ele,
            const axis2_env_t *env,
            axis2_qname_t *fault_qname);
    
    axis2_qname_t *(AXIS2_CALL *
    get_ref) (
            void *iface_fault_ele,
            const axis2_env_t *env);
    
    void *(AXIS2_CALL *
    get_interface_fault_element) (
            void *iface_fault_ele,
            const axis2_env_t *env);
    
    axis2_status_t (AXIS2_CALL *
    set_msg_label) (
            void *iface_fault_ele,
            const axis2_env_t *env,
            void *msg_label);

    void *(AXIS2_CALL *
    get_msg_label) (
            void *iface_fault_ele,
            const axis2_env_t *env);
     
    axis2_status_t (AXIS2_CALL *
    set_direction) (
            void *iface_fault_ele,
            const axis2_env_t *env,
            void *dir);

    void *(AXIS2_CALL *
    get_direction) (
            void *iface_fault_ele,
            const axis2_env_t *env);
    

};

union axis2_woden_interface_fault_ref_element_base
{
    axis2_woden_documentable_element_t documentable_element;
    axis2_woden_configurable_element_t configurable_element;
    axis2_woden_nested_element_t nested_element;
};

struct axis2_woden_interface_fault_ref_element
{
    axis2_woden_interface_fault_ref_element_base_t base;
    axis2_woden_interface_fault_ref_element_ops_t *ops;
};

AXIS2_EXTERN axis2_woden_interface_fault_ref_element_t * AXIS2_CALL
axis2_woden_interface_fault_ref_element_create(
        const axis2_env_t *env);

/************************Woden C Internal Methods******************************/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_woden_interface_fault_ref_element_resolve_methods(
        axis2_woden_interface_fault_ref_element_t *interface_fault_ref_element,
        const axis2_env_t *env,
        axis2_hash_t *methods);
/************************End of Woden C Internal Methods***********************/

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_FREE(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         free (interface_fault_ref_element, env))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_TYPE(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         type (interface_fault_ref_element, env))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_SET_REF(interface_fault_ref_element, env, fault_qname) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         set_ref (interface_fault_ref_element, env, fault_qname))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_GET_REF(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
        get_ref  (interface_fault_ref_element, env))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_GET_INTERFACE_FAULT_ELEMENT(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
        get_interface_fault_element  (interface_fault_ref_element, env))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_SET_MSG_LABEL(interface_fault_ref_element, env, msg_label) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         set_msg_label (interface_fault_ref_element, env, msg_label))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_GET_MSG_LABEL(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         get_msg_label (interface_fault_ref_element, env))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_SET_DIRECTION(interface_fault_ref_element, env, dir) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         set_direction (interface_fault_ref_element, env, dir))

#define AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_GET_DIRECTION(interface_fault_ref_element, env) \
      (((axis2_woden_interface_fault_ref_element_t *) interface_fault_ref_element)->ops->\
         get_direction (interface_fault_ref_element, env))




/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_WODEN_INTERFACE_FAULT_REF_ELEMENT_H */
