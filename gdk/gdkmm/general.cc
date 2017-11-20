/* Copyright 2002      The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gdkmm/cairoutils.h>
#include <gdkmm/general.h>
#include <gdk/gdk.h>


namespace Gdk
{

namespace Cairo
{

void set_source_rgba(const ::Cairo::RefPtr< ::Cairo::Context >& context, const Gdk::RGBA& color)
{
  gdk_cairo_set_source_rgba(context->cobj(), const_cast<GdkRGBA*>(color.gobj()));
}

void set_source_pixbuf(const ::Cairo::RefPtr< ::Cairo::Context >& context, const Glib::RefPtr<Gdk::Pixbuf>& pixbuf, double pixbuf_x, double pixbuf_y)
{
  gdk_cairo_set_source_pixbuf(context->cobj(), pixbuf->gobj(), pixbuf_x, pixbuf_y);
}


void add_rectangle_to_path(const ::Cairo::RefPtr< ::Cairo::Context >& context, const Gdk::Rectangle& rectangle)
{
  gdk_cairo_rectangle(context->cobj(), const_cast<GdkRectangle*>(rectangle.gobj()));
}

void add_region_to_path(const ::Cairo::RefPtr< ::Cairo::Context >& context, const ::Cairo::RefPtr< ::Cairo::Region>& region)
{
  gdk_cairo_region(context->cobj(), (region ? region->cobj() : nullptr));
}

bool get_clip_rectangle(const ::Cairo::RefPtr< ::Cairo::Context >& context, Gdk::Rectangle& rectangle)
{
  return gdk_cairo_get_clip_rectangle(context->cobj(), rectangle.gobj());
}

bool get_clip_rectangle(const ::Cairo::RefPtr< ::Cairo::Context >& context)
{
  return gdk_cairo_get_clip_rectangle(context->cobj(), nullptr);
}

::Cairo::RefPtr< ::Cairo::Region> create_region_from_surface(const ::Cairo::RefPtr< ::Cairo::Surface>& surface)
{
  return Gdk::Cairo::wrap(gdk_cairo_region_create_from_surface(surface->cobj()), true);
}

::Cairo::RefPtr< ::Cairo::Surface> create_surface_from_pixbuf(const Glib::RefPtr<const Gdk::Pixbuf>& pixbuf,
  int scale, const Glib::RefPtr<Gdk::Window>& for_window)
{
  return Gdk::Cairo::wrap(gdk_cairo_surface_create_from_pixbuf(
    pixbuf->gobj(), scale, for_window ? for_window->gobj() : nullptr), true);
}

void draw_from_gl(const ::Cairo::RefPtr< ::Cairo::Context >& context,
  const Glib::RefPtr<Gdk::Window>& window, int source, int source_type,
  int buffer_scale, int x, int y, int width, int height)
{
  gdk_cairo_draw_from_gl(context->cobj(), window->gobj(), source, source_type,
    buffer_scale, x, y, width, height);
}

void upload_surface_to_gl(const ::Cairo::RefPtr< ::Cairo::Surface>& surface,
  int target, int width, int height, const Glib::RefPtr<GLContext>& context)
{
  gdk_cairo_surface_upload_to_gl(surface->cobj(), target, width, height,
    context ? context->gobj() : nullptr);
}

} //namespace Cairo

} //namespace Gdk
