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

#ifndef AXIS2_WODEN_IMPORT_ELEMENT_H
#define AXIS2_WODEN_IMPORT_ELEMENT_H

/**
 * @file axis2_woden_import_element.h
 * @brief Axis2 Import Element Interface
 * This interface represents a &lt;import&gt; XML element 
 * information item. It declares the behaviour required to support 
 * parsing, creating and manipulating a &lt;import&gt; element.
 *
 */

#include <axis2_allocator.h>
#include <axis2_env.h>
#include <axis2_error.h>
#include <axis2_string.h>
#include <axis2_utils.h>
#include <axis2_hash.h>
#include <axis2_qname.h>
#include <axis2_uri.h>
#include <woden/axis2_woden.h>
#include <woden/wsdl20/xml/axis2_woden_documentable_element.h>
#include <woden/wsdl20/xml/axis2_woden_nested_element.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct axis2_woden_import_element axis2_woden_import_element_t;
typedef struct axis2_woden_import_element_ops axis2_woden_import_element_ops_t;
typedef union axis2_woden_import_element_base axis2_woden_import_element_base_t;

/** @defgroup axis2_woden_import_element Import Element
  * @ingroup axis2_wsdl
  * @{
  */

struct axis2_woden_import_element_ops
{
   /** 
     * Deallocate memory
     * @return status code
     */
    axis2_status_t (AXIS2_CALL *
    free) (
            void *import_el,
            const axis2_env_t *env);
    
    axis2_woden_obj_types_t (AXIS2_CALL *
    type) (void *import_el,
            const axis2_env_t *env);
     
    axis2_status_t (AXIS2_CALL *
    set_namespace) (void *import_el,
            const axis2_env_t *env,
            axis2_uri_t *ns_uri);

    axis2_uri_t *(AXIS2_CALL *
    get_namespace) (void *import_el,
            const axis2_env_t *env);

   
    axis2_status_t (AXIS2_CALL *
    set_location) (void *import_el,
            const axis2_env_t *env,
            axis2_uri_t *loc_uri);

    axis2_uri_t *(AXIS2_CALL *
    get_location) (void *import_el,
            const axis2_env_t *env);

    axis2_status_t (AXIS2_CALL *
    set_desc_element) (void *import_el,
            const axis2_env_t *env,
            void *desc);

    void *(AXIS2_CALL *
    get_desc_element) (void *import_el,
            const axis2_env_t *env);

};


struct axis2_woden_import_element
{
    axis2_woden_documentable_element_t documentable_element;
    axis2_woden_import_element_ops_t *ops;
};

/************************Woden C Internal Methods******************************/
axis2_status_t AXIS2_CALL
axis2_woden_import_element_resolve_methods(
        axis2_woden_import_element_t *import_element,
        const axis2_env_t *env,
        axis2_hash_t *methods);
/************************End of Woden C Internal Methods***********************/

#define AXIS2_WODEN_IMPORT_ELEMENT_FREE(import_el, env) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         free (import_el, env))

#define AXIS2_WODEN_IMPORT_ELEMENT_TYPE(import_el, env) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         type (import_el, env))

#define AXIS2_WODEN_IMPORT_ELEMENT_SET_NAMESPACE(import_el, env, ns_uri) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         set_namespace(import_el, env, ns_uri))

#define AXIS2_WODEN_IMPORT_ELEMENT_GET_NAMESPACE(import_el, env) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         get_namespace(import_el, env))

#define AXIS2_WODEN_IMPORT_ELEMENT_SET_LOCATION(import_el, env, loc_uri) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         set_location(import_el, env, loc_uri))

#define AXIS2_WODEN_IMPORT_ELEMENT_GET_LOCATION(import_el, env) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         get_location(import_el, env))

#define AXIS2_WODEN_IMPORT_ELEMENT_SET_DESC_ELEMENT(import_el, env, desc) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         set_desc_element(import_el, env, desc))

#define AXIS2_WODEN_IMPORT_ELEMENT_GET_DESC_ELEMENT(import_el, env) \
      (((axis2_woden_import_element_t *) import_el)->ops->\
         get_desc_element(import_el, env))

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_WODEN_IMPORT_ELEMENT_H */
