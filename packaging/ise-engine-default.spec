Name:       ise-engine-default
Summary:    Multilingual Keyboard ISE
Version:    0.1.5023
Release:    1
Group:      TO_BE/FILLED_IN
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(isf)

%description
Multilingual Keyboard Input Service Engine (ISE) is a keyboard input method (IM), and
it is based on Input Service Framework(ISF).

%prep
%setup -q

%build

./bootstrap
%configure --prefix=%{_prefix} --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install


%files
%defattr(-,root,root,-)
/usr/lib/scim-1.0/1.4.0/IMEngine/ise-engine-default.so
/usr/share/scim/icons/isf-default.png
