#ifndef __GWEBKITJS_VALUE_H__
#define __GWEBKITJS_VALUE_H__

#include <glib-object.h>
#include <JavaScriptCore/JSObjectRef.h>

/***************************************************************************
 *   Copyright (C) 2012~2012 by Yichao Yu                                  *
 *   yyc1992@gmail.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#define GWEBKITJS_TYPE_VALUE (gwebkitjs_value_get_type())
#define GWEBKITJS_VALUE(obj)                                  \
    (G_TYPE_CHECK_INSTANCE_CAST((obj), GWEBKITJS_TYPE_VALUE,  \
                                GWebKitJSValue))
#define GWEBKITJS_IS_VALUE(obj)                               \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), GWEBKITJS_TYPE_VALUE))
#define GWEBKITJS_VALUE_CLASS(klass)                          \
    (G_TYPE_CHECK_CLASS_CAST((klass), GWEBKITJS_TYPE_VALUE,   \
                             GWebKitJSValueClass))
#define GWEBKITJS_IS_VALUE_CLASS(klass)                       \
    (G_TYPE_CHECK_CLASS_TYPE((klass), GWEBKITJS_TYPE_VALUE))
#define GWEBKITJS_VALUE_GET_CLASS(obj)                        \
    (G_TYPE_INSTANCE_GET_CLASS((obj), GWEBKITJS_TYPE_VALUE,   \
                               GWebKitJSValueClass))

typedef struct _GWebKitJSValue GWebKitJSValue;
typedef struct _GWebKitJSValuePrivate GWebKitJSValuePrivate;
typedef struct _GWebKitJSValueClass GWebKitJSValueClass;

typedef struct _GWebKitJSContext GWebKitJSContext;

struct _GWebKitJSValue {
    GObject parent;
    GWebKitJSValuePrivate *priv;
};

struct _GWebKitJSValueClass {
    GObjectClass parent_class;
};

typedef enum {
    GWEBKITJS_VALUE_TYPE_UNKNOWN,
    GWEBKITJS_VALUE_TYPE_UNDEFINED,
    GWEBKITJS_VALUE_TYPE_NULL,
    GWEBKITJS_VALUE_TYPE_BOOLEAN,
    GWEBKITJS_VALUE_TYPE_NUMBER,
    GWEBKITJS_VALUE_TYPE_STRING,
    GWEBKITJS_VALUE_TYPE_OBJECT,
} GWebKitJSValueType;

#ifdef __cplusplus
extern "C" {
#endif
    GType gwebkitjs_value_get_type();
    GWebKitJSValue *gwebkitjs_value_new(GType type, GWebKitJSContext *ctx,
                                        JSValueRef jsvalue);

    JSValueRef gwebkitjs_value_get_value(GWebKitJSValue *self);
    void gwebkitjs_value_protect_value(GWebKitJSValue *self);
    void gwebkitjs_value_unprotect_value(GWebKitJSValue *self);

    GWebKitJSValueType gwebkitjs_value_get_value_type(GWebKitJSValue *self,
                                                      GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_bool(GWebKitJSValue *self,
                                     GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_null(GWebKitJSValue *self,
                                     GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_number(GWebKitJSValue *self,
                                       GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_string(GWebKitJSValue *self,
                                       GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_object(GWebKitJSValue *self,
                                       GWebKitJSContext *ctx);
    gboolean gwebkitjs_value_is_undefined(GWebKitJSValue *self,
                                          GWebKitJSContext *ctx);

    gboolean gwebkitjs_value_is_instance_of(GWebKitJSValue *self,
                                            GWebKitJSContext *ctx,
                                            GWebKitJSValue *construct,
                                            GError **error);
    gboolean gwebkitjs_value_is_of_class(GWebKitJSValue *self,
                                         GWebKitJSContext *ctx,
                                         GType klass, GError **error);
    gchar *gwebkitjs_value_to_json_str(GWebKitJSValue *self, guint indent,
                                       GError **error);
#ifdef __cplusplus
}
#endif

#endif /* __GWEBKITJS_VALUE_H__ */
