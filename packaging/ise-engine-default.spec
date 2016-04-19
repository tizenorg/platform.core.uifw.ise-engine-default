Name:       ise-engine-default
Summary:    Multilingual Keyboard ISE
Version:    1.0.5
Release:    1
Group:      Graphics & UI Framework/Input
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(isf)

%description
Multilingual Keyboard Input Service Engine (ISE) is a keyboard input method (IM), and
it is based on Input Service Framework(ISF).

%prep
%setup -q

%build
export CFLAGS+=" -Werror"
export CXXFLAGS+=" -Werror"
%autogen
%configure --prefix=%{_prefix} --disable-static

make %{?_smp_mflags} 

%install
rm -rf %{buildroot}

%make_install

%post

%postun

%files
%manifest %{name}.manifest
%defattr(-,root,root,-)
%{_libdir}/scim-1.0/1.4.0/IMEngine/ise-engine-default.so
%{_datadir}/scim/icons/isf-default.png
%{_datadir}/packages/*
%license LICENSE.APLv2
