from django.contrib import admin
from django.urls import path, re_path
from django.conf.urls import include
urlpatterns = [
 path(r'^admin/', admin.site.urls),
 re_path('', include('arithmetic.urls')),
]